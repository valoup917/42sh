/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_five
*/

#include <sys/types.h>
#include <sys/wait.h>
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

void sh_thread_pstop(shell_t *sh, list_t *ll, pipe_t *p, int st)
{
    if (WIFSTOPPED(st) || ll->list_bg == true) {
        sh->jobs = utils_jb_rmove(sh->jobs, strdup(p->av[0]), p->pipe_pid);
        if (sh->jobs) {
            (ll->list_bg == true) ?
            printf("[%d] %d\n", sh->jobs->id, sh->jobs->pid) :
            printf(MESS_SUSPENDED, sh->jobs->id, sh->jobs->pid,
            sh->jobs->name);
        }
    }
}

pid_t sh_thread_ptry(shell_t *sh, pipe_t *p)
{
    pid_t pgid = 0;

    for (; p; p = p->next) {
        shell_prdi_error_open(sh, p);
        if (p->pipe_cmd->command_end_idx == DELIMIT_PAR) {
            sh->sh_rt = sh_get_par(sh, p);
        } else if (utils_cmd_array(sh, p) == true) {
            pgid = tmp_sh_thread_cmd(sh, p, pgid);
        } else {
            sh->sh_rt = 1;
        }
        shell_prdi_error(p);
    }
    return pgid;
}

void sh_thread_pwait(shell_t *sh, list_t *ll, pipe_t *p, pid_t pgid)
{
    int st = 0;

    for (shell_replace_groups(pgid); p; p = p->next) {
        st = 0;
        if (ll->list_bg == true) {
            waitpid(-pgid, &st, WNOHANG | WUNTRACED);
        } else {
            waitpid(-pgid, &st, WUNTRACED);
        }
        sh->sh_rt = shell_signal_status(st);
        sh_thread_pstop(sh, ll, p, st);
    }
    shell_replace_groups(sh->pid.pgid);
}

cmd_t *sh_bq_fork_head(pipe_t *p, cmd_t *cmd, int *fd)
{
    char *s = NULL;
    size_t max = 0;

    while ((s = my_get_next_line(fd[0])) != NULL) {
        max += strlen(s);
        if (max >= 66666666) {
            close(fd[0]);
            kill(p->pipe_pid, SIGKILL);
            return cmd;
        }
        cmd = utils_cmd_radd(cmd, s, DELIMIT_WITHOUT);
    }
    close(fd[0]);
    return cmd;
}

cmd_t *sh_bq_fork(shell_t *sh, pipe_t *p, cmd_t *cmd)
{
    int fd[2];

    if (pipe(fd) == -1) {
        fprintf(stderr, ERROR_FUNCTION, "pipe");
        shell_status_close(sh, EXIT_FAILURE);
    }
    p->pipe_pid = fork();
    if (p->pipe_pid == -1) {
        fprintf(stderr, ERROR_FUNCTION, "fork");
        shell_status_close(sh, EXIT_FAILURE);
    } else if (p->pipe_pid == 0) {
        close(fd[0]);
        sh->fd[PIPE_FD_OUT] = fd[1];
        sh_command_control(sh, strdup(cmd->commands));
        shell_status_close(sh, sh->sh_rt);
    }
    close(fd[1]);
    return sh_bq_fork_head(p, cmd, fd);
}