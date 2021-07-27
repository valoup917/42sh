/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_cmd_move
*/

#include <stdlib.h>
#include "just_shell.h"

cmd_t *utils_cmd_radd(cmd_t *cmd, char *s, short i)
{
    cmd_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->prev = cmd;
    res->next = NULL;
    res->commands = s;
    res->command_end_idx = i;
    if (cmd) {
        if (cmd->next) {
            res->next = cmd->next;
            cmd->next->prev = res;
        }
        cmd->next = res;
    }
    return res;
}

void utils_pipe_dcmd(pipe_t *p, cmd_t *cmd)
{
    if (cmd->prev) {
        cmd->prev->next = cmd->next;
    } else {
        p->pipe_cmd = cmd->next;
    }
    if (cmd->next) {
        cmd->next->prev = cmd->prev;
    }
    if (cmd->commands) {
        free(cmd->commands);
    }
    free(cmd);
}

void utils_cmd_dlist(cmd_t *cmd)
{
    for (cmd_t *tmp; cmd; free(tmp)) {
        tmp = cmd;
        cmd = cmd->next;
        if (tmp->commands) {
            free(tmp->commands);
        }
    }
}

void utils_cmd_dnode(shell_t *sh, cmd_t *cmd)
{
    if (cmd->prev) {
        cmd->prev->next = cmd->next;
    } else {
        sh->commands = cmd->next;
    }
    if (cmd->next) {
        cmd->next->prev = cmd->prev;
    }
    if (cmd->commands) {
        free(cmd->commands);
    }
    free(cmd);
}

void utils_cmd_pnode(cmd_t *cmd)
{
    if (cmd->prev) {
        cmd->prev->next = NULL;
    }
    if (cmd->next) {
        cmd->next->prev = NULL;
    }
    if (cmd->commands) {
        free(cmd->commands);
    }
    free(cmd);
}