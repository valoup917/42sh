/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_cmd_move_two
*/

#include <stdlib.h>
#include "just_shell.h"

cmd_t *utils_cmd_move_back(cmd_t *cmd)
{
    for (; cmd && cmd->prev; cmd = cmd->prev);
    return cmd;
}

void utils_pipe_dlist(pipe_t *p)
{
    for (pipe_t *t; p; free(t)) {
        t = p;
        p = p->next;
        if (t->av)
            free(t->av);
        if (t->pipe_path)
            free(t->pipe_path);
        if (t->redirection[REDIRECT_RIGHT])
            free(t->redirection[REDIRECT_RIGHT]);
        if (t->redirection[REDIRECT_TRIGHT])
            free(t->redirection[REDIRECT_TRIGHT]);
        if (t->redirection[REDIRECT_LEFT])
            free(t->redirection[REDIRECT_LEFT]);
        if (t->redirection[REDIRECT_TLEFT])
            free(t->redirection[REDIRECT_TLEFT]);
        if (t->pipe_cmd)
            utils_cmd_dlist(t->pipe_cmd);
    }
}

static void init_utils_pipe_ar(pipe_t *r, cmd_t *cmd, pipe_t *p)
{
    r->prev = p;
    r->next = NULL;
    r->pipe_cmd = cmd;
    r->av = NULL;
    r->ac = 0;
    r->pipe_pid = 0;
    r->redirection[REDIRECT_RIGHT] = NULL;
    r->redirection[REDIRECT_TRIGHT] = NULL;
    r->redirection[REDIRECT_LEFT] = NULL;
    r->redirection[REDIRECT_TLEFT] = NULL;
    r->fd[PIPE_FD_IN] = -1;
    r->fd[PIPE_FD_OUT] = -1;
    r->pipe_path = NULL;
}

pipe_t *utils_pipe_ar(pipe_t *p, cmd_t *cmd)
{
    pipe_t *r = malloc(sizeof(*r));

    if (!r) {
        return NULL;
    }
    init_utils_pipe_ar(r, cmd, p);
    if (p) {
        if (p->next) {
            r->next = p->next;
            p->next->prev = r;
        }
        p->next = r;
    }
    return r;
}

pipe_t *utils_pipe_mouvement_back(pipe_t *p)
{
    for (; p && p->prev; p = p->prev);
    return p;
}