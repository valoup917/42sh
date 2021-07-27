/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser_bg
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

bool parser_bg_fnd_tmp(pipe_t *p, list_t *ll, shell_t *sh)
{
    for (; p; p = p->next) {
        if (parser_bg_cmd_tmp(p, ll, sh) == false) {
            return false;
        }
    }
    return true;
}

bool parser_bg_cmd_tmp(pipe_t *p, list_t *ll, shell_t *sh)
{
    for (cmd_t *cmd = p->pipe_cmd; cmd; cmd = cmd->next) {
        if (cmd->command_end_idx == DELIMIT_BACKGROUND) {
            if (p->next || (!cmd->prev && !cmd->next)) {
                fprintf(stdout, "%s\n", "Invalid null command.");
                return false;
            }
            ll->list_bg = true;
            if (p->pipe_cmd == cmd) {
                p->pipe_cmd = cmd->next;
            }
            utils_cmd_dnode(sh, cmd);
            return parser_bg_fnd_tmp(p, ll, sh);
        }
    }
    return true;
}

bool parser_bg(shell_t *sh)
{
    for (list_t *tmp = sh->list; tmp; tmp = tmp->next) {
        if (parser_bg_fnd_tmp(tmp->p, tmp, sh) == false) {
            return false;
        }
    }
    return true;
}

bool parser_del_more(shell_t *sh)
{
    for (cmd_t *cmd = sh->commands; cmd && cmd->next; cmd = cmd->next) {
        if (cmd->command_end_idx != DELIMIT_WITHOUT &&
        cmd->next->command_end_idx != DELIMIT_WITHOUT &&
        (IF_SEPARATOR(cmd->command_end_idx)) &&
        (IF_SEPARATOR(cmd->next->command_end_idx))) {
            if (GET_MY_ID(cmd->command_end_idx) != DELIMIT_SEPARATOR ||
            (GET_MY_ID(cmd->command_end_idx) == DELIMIT_SEPARATOR &&
            GET_MY_ID(cmd->next->command_end_idx) == DELIMIT_OR)) {
                fprintf(stdout, "%s\n", "Invalid null command.");
                return false;
            } else {
                utils_cmd_dnode(sh, cmd->next);
                return parser_del_more(sh);
            }
        }
    }
    return true;
}

bool parser_check_len_max(shell_t *sh)
{
    cmd_t *cmd = sh->commands;

    if (cmd) {
        if (cmd->command_end_idx != DELIMIT_WITHOUT &&
        GET_MY_ID(cmd->command_end_idx) == DELIMIT_OR) {
            fprintf(stdout, "%s\n", "Invalid null command.");
            return false;
        }
        for (; cmd && cmd->next; cmd = cmd->next);
        if (cmd != sh->commands) {
            if (cmd->command_end_idx != DELIMIT_WITHOUT &&
            GET_MY_TYPE(cmd->command_end_idx) == DELIMIT_SEP &&
            GET_MY_ID(cmd->command_end_idx) != DELIMIT_SEPARATOR) {
                fprintf(stdout, "%s\n", "Invalid null command.");
                return false;
            }
        }
    }
    return true;
}