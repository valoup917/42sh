/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser_redirection
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

bool parser_redirection_check_pipe(cmd_t *cmd)
{
    for (cmd_t *tmp = cmd; tmp; tmp = tmp->next) {
        if (tmp->command_end_idx != DELIMIT_WITHOUT &&
        (IF_PIPE(tmp->command_end_idx))) {
            if ((tmp == cmd || !tmp->next) ||
            (tmp->next && tmp->next->command_end_idx != DELIMIT_WITHOUT &&
            (IF_PIPE(tmp->next->command_end_idx)))) {
                fprintf(stdout, "%s\n", "Invalid null command.");
                return false;
            }
        }
    }
    return true;
}

void parser_redirection_get_pipe(list_t *ll)
{
    cmd_t *tmp = ll->list_cmd;

    if (ll && ll->list_cmd) {
        ll->p = utils_pipe_ar(ll->p, ll->list_cmd);
    }
    for (; tmp; tmp = tmp->next) {
        if (tmp->prev && tmp->prev->command_end_idx != DELIMIT_WITHOUT &&
        (IF_PIPE(tmp->prev->command_end_idx))) {
            ll->p = utils_pipe_ar(ll->p, tmp);
            utils_cmd_pnode(tmp->prev);
        }
    }
    ll->list_cmd = NULL;
    ll->p = utils_pipe_mouvement_back(ll->p);
}

bool parser_redirection_par_pipe(pipe_t *p)
{
    for (cmd_t *tmp; p; p = p->next) {
        for (tmp = p->pipe_cmd; tmp; tmp = tmp->next) {
            if (tmp->command_end_idx == DELIMIT_PAR) {
                return true;
            }
        }
    }
    return true;
}

bool sh_parser_pipe(shell_t *sh)
{
    for (list_t *tmp = sh->list; tmp; tmp = tmp->next) {
        if (parser_redirection_check_pipe(tmp->list_cmd) == false) {
            utils_linked_list_dlist(sh->list);
            sh->list = NULL;
            return false;
        }
        parser_redirection_get_pipe(tmp);
        if (parser_redirection_par_pipe(tmp->p) == false
        || parser_redirection(tmp) == false) {
            utils_linked_list_dlist(sh->list);
            sh->list = NULL;
            return false;
        }
    }
    return true;
}