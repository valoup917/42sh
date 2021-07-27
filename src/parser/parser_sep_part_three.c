/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser_sep_part_three
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

void parser_cmd_dquote(cmd_t *cmd)
{
    for (; cmd; cmd = cmd->next) {
        if (cmd->command_end_idx == DELIMIT_DQUOTE) {
            parser_sep_tmp_quotes_threat(cmd->commands);
        }
    }
}

cmd_t *parser_cmd_geto(cmd_t *cmd)
{
    for (; cmd && cmd->next; cmd = cmd->next);
    return cmd;
}

cmd_t *parser_cmd_historyp(shell_t *sh, cmd_t *cmd, char *s)
{
    cmd_t *shtmp = sh->commands;
    cmd_t *before = NULL;
    cmd_t *next = cmd->next;

    sh_parser(sh, s, false);
    if (!sh->commands) {
        sh->commands = shtmp;
        return cmd->next;
    }
    before = parser_cmd_geto(sh->commands);
    if (cmd->next) {
        cmd->next->prev = before;
    }
    if (before) {
        before->next = cmd->next;
    }
    cmd->next = sh->commands;
    sh->commands = shtmp;
    utils_cmd_dnode(sh, cmd);
    return next;
}

void parser_cmd_hist(shell_t *sh, cmd_t *cmd)
{
    for (char *s = NULL; cmd; ) {
        s = NULL;
        if (cmd->command_end_idx == DELIMIT_DQUOTE ||
        cmd->command_end_idx == DELIMIT_BQUOTE) {
            s = utils_hs(sh, cmd->commands);
            if (s) {
                free(cmd->commands);
                cmd->commands = strdup(s);
            }
            cmd = cmd->next;
        } else if (cmd->command_end_idx == DELIMIT_WITHOUT) {
            s = utils_hs(sh, cmd->commands);
            cmd = (s) ? parser_cmd_historyp(sh, cmd, s) : cmd->next;
        } else {
            cmd = cmd->next;
        }
    }
}

short parser_end_of_type(char *s, int *n)
{
    if (*n > 0 && s[*n - 1] == '\\') {
        return DELIMIT_WITHOUT;
    }
    for (short i = 0; GET_MY_TYPE(i) != DELIMIT_WITHOUT; i += 1) {
        if (!my_strncmp(&s[*n], PARSER_ARRAY[i].parser_end,
        strlen(PARSER_ARRAY[i].parser_end))) {
            return i;
        }
    }
    return DELIMIT_WITHOUT;
}