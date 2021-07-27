/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_jobs
*/

#include <sys/wait.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include "just_shell.h"

static int builtins_jobs_bg_action(shell_t *sh, jobs_t *jb)
{
    int st = 0;

    sh->sh_rt = 0;
    if (!sh->sh_wr) {
        shell_replace_groups(getpgid(jb->pid));
        kill(-jb->pid, SIGCONT);
        waitpid(-jb->pid, &st, WUNTRACED);
        sh->sh_rt = shell_signal_status(st);
        if (!WIFSTOPPED(st)) {
            utils_jb_dnode(sh, jb);
        }
        shell_replace_groups(sh->pid.pgid);
    }
    return sh->sh_rt;
}

int builtins_fg(int ac, char **av, shell_t *sh)
{
    jobs_t *jb = utils_jb_move_back(sh->jobs);
    unsigned i = 0;

    if (ac > 1) {
        for (i = atoi(av[1]); jb && jb->id != i; jb = jb->next);
    }
    if (!jb) {
        if (sh->sh_wr) {
            fprintf(stderr, "Jobs not found.\n");
        }
        return 1;
    }
    return builtins_jobs_bg_action(sh, jb);
}

int builtins_jobs(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh)
{
    jobs_t *jb;

    if (!sh->sh_wr) {
        return 0;
    }
    for (jb = utils_jb_move_back(sh->jobs); jb; jb = jb->next) {
        printf("[%u]\t%s\n", jb->id, jb->name);
    }
    return 0;
}