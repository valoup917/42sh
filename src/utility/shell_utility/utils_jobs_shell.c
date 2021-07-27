/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_jobs_shell
*/

#include <stdlib.h>
#include <signal.h>
#include "just_shell.h"

void utils_jb_dnode(shell_t *sh, jobs_t *jb)
{
    if (jb->prev) {
        jb->prev->next = jb->next;
    } else {
        sh->jobs = jb->next;
    }
    if (jb->next) {
        jb->next->prev = jb->prev;
    }
}

void utils_jb_dlist(shell_t *sh, jobs_t *jb)
{
    for (jobs_t *tmp; jb; utils_jb_dnode(sh, tmp)) {
        tmp = jb;
        jb = jb->next;
    }
}

jobs_t *utils_jb_move_back(jobs_t *jb)
{
    for (; jb && jb->prev; jb = jb->prev);
    return jb;
}

jobs_t *utils_jb_move_end(jobs_t *jb)
{
    for (; jb && jb->next; jb = jb->next);
    return jb;
}

jobs_t *utils_jb_rmove(jobs_t *jb, char *s, pid_t pid)
{
    jobs_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->prev = jb;
    res->next = NULL;
    res->name = s;
    res->pid = pid;
    res->id = 1;
    if (jb) {
        res->id = jb->id + 1;
        jb->next = res;
    }
    return res;
}