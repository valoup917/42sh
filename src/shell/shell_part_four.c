/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_four
*/

#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <pwd.h>
#include "just_shell.h"

static void sh_linked_stop(list_t *ll, short id)
{
    for (; ll && ll->list_sep == id; ll = ll->next) {
        ll->list_threat = false;
    }
}

bool sh_linked_thread(shell_t *sh)
{
    list_t *ll = sh->list;

    for (pid_t pgid; ll; ll = ll->next) {
        if (ll->list_threat == true) {
            pgid = sh_thread_ptry(sh, ll->p);
            sh_thread_pwait(sh, ll, ll->p, pgid);
            (sh->sh_rt != EXIT_SUCCESS) ?
            sh_linked_stop(ll->next, DELIMIT_AND) :
            sh_linked_stop(ll->next, DELIMIT_OR);
        }
    }
    return true;
}

void get_sh_sig(bool check)
{
    signal(SIGQUIT, (check) ? SIG_IGN : SIG_DFL);
    if (isatty(STDIN_FILENO)) {
        signal(SIGINT, (check) ? SIG_IGN : SIG_DFL);
        signal(SIGTSTP, (check) ? SIG_IGN : SIG_DFL);
        signal(SIGTTIN, (check) ? SIG_IGN : SIG_DFL);
        signal(SIGTTOU, (check) ? SIG_IGN : SIG_DFL);
        signal(SIGTERM, (check) ? SIG_IGN : SIG_DFL);
    }
}

void tmp_sh_thread_pcmd(shell_t *sh, pipe_t *p)
{
    sh->sh_wr = true;
    sh->sh_rt = 0;
    get_sh_sig(false);
    if (check_builtins(p->av[0]) != -1) {
        sh->sh_rt = builtins_execution(sh, p);
    } else if ((p->pipe_path = sh_path_env(sh, p->av[0])) != NULL) {
        execve(p->pipe_path, p->av, sh->sh_array);
        if (errno == ENOEXEC) {
            fprintf(stdout, ERROR_FORMAT, p->av[0]);
        } else
            fprintf(stdout, ERROR_ALLOW, p->av[0]);
        sh->sh_rt = 1;
    } else {
        sh->sh_rt = 1;
        fprintf(stderr, ERROR_NOT_FOUND, p->av[0]);
    }
    shell_status_close(sh, sh->sh_rt);
}

pid_t tmp_sh_thread_cmd(shell_t *sh, pipe_t *p, pid_t pgid)
{
    p->pipe_pid = fork();
    if (p->pipe_pid == -1) {
        fprintf(stderr, ERROR_FUNCTION, "fork");
        shell_status_close(sh, 1);
    } if (p->pipe_pid != 0) {
        if (!p->prev)
            pgid = p->pipe_pid;
        setpgid(p->pipe_pid, pgid);
        if (check_builtins(p->av[0]) != -1)
            sh->sh_rt = builtins_execution(sh, p);
    } if (p->pipe_pid == 0) {
        get_sh_sig(false);
        if (shell_aredi_dp(sh, p) == false)
            shell_status_close(sh, 1);
        if (p->next)
            close(p->next->fd[PIPE_FD_IN]);
        tmp_sh_thread_pcmd(sh, p);
    }
    return pgid;
}