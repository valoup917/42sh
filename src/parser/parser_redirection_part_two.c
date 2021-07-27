/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser_redirection_part_two
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

cmd_t *parser_redirection_dcmd(pipe_t *p, cmd_t *cmd)
{
    cmd_t *tmp;

    cmd = cmd->next;
    utils_pipe_dcmd(p, cmd->prev);
    tmp = cmd->next;
    utils_pipe_dcmd(p, cmd);
    return tmp;
}

bool parser_redirection_ar(pipe_t *p, cmd_t *cmd)
{
    if (p->next || p->redirection[REDIRECT_RIGHT] ||
    p->redirection[REDIRECT_TRIGHT]) {
        fprintf(stdout, "%s\n", "Ambiguous output redirect.");
        return false;
    }
    if (!cmd->next || !cmd->next->commands) {
        fprintf(stdout, "%s\n", "Missing name for redirect.");
        return false;
    }
    if (cmd->command_end_idx == DELIMIT_DRIGHT) {
        p->redirection[REDIRECT_TRIGHT] = strdup(cmd->next->commands);
    } else if (cmd->command_end_idx == DELIMIT_RIGHT) {
        p->redirection[REDIRECT_RIGHT] = strdup(cmd->next->commands);
    }
    return true;
}

bool parser_redirection_al(pipe_t *p, cmd_t *cmd)
{
    if (p->prev || p->redirection[REDIRECT_LEFT] ||
    p->redirection[REDIRECT_TLEFT]) {
        fprintf(stdout, "%s\n", "Ambiguous input redirect.");
        return false;
    }
    if (!cmd->next || !cmd->next->commands) {
        fprintf(stdout, "%s\n", "Missing name for redirect.");
        return false;
    }
    if (cmd->command_end_idx == DELIMIT_DLEFT) {
        p->redirection[REDIRECT_TLEFT] = strdup(cmd->next->commands);
    } else if (cmd->command_end_idx == DELIMIT_LEFT) {
        p->redirection[REDIRECT_LEFT] = strdup(cmd->next->commands);
    }
    return true;
}

bool parser_redirection_found(pipe_t *p, cmd_t *cmd)
{
    for (; cmd; ) {
        if (cmd->command_end_idx == DELIMIT_DRIGHT ||
        cmd->command_end_idx == DELIMIT_RIGHT) {
            if (parser_redirection_ar(p, cmd) == false)
                return false;
            cmd = parser_redirection_dcmd(p, cmd);
        } else if (cmd->command_end_idx == DELIMIT_DLEFT ||
        cmd->command_end_idx == DELIMIT_LEFT) {
            if (parser_redirection_al(p, cmd) == false)
                return false;
            cmd = parser_redirection_dcmd(p, cmd);
        } else
            cmd = cmd->next;
    }
    if (p->pipe_cmd == NULL) {
        fprintf(stdout, "%s\n", "Invalid null command.");
        return false;
    }
    return true;
}

bool parser_redirection(list_t *ll)
{
    for (pipe_t *tmp = ll->p; tmp; tmp = tmp->next) {
        if (parser_redirection_found(tmp, tmp->pipe_cmd) == false) {
            return false;
        }
    }
    return true;
}