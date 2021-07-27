/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** paser_sep
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

void parser_dlim(shell_t *sh)
{
    cmd_t *cmd = sh->commands;
    cmd_t *cmdf = sh->commands;
    int remove = 0;

    if (cmd) {
        for (; cmd && cmd->next; cmd = cmd->next);
        if (cmd != cmdf && cmd->command_end_idx != DELIMIT_WITHOUT &&
        (IF_SEPARATOR(cmd->command_end_idx))) {
            remove++;
            utils_cmd_dnode(sh, cmd);
        }
        if (cmdf->command_end_idx != DELIMIT_WITHOUT &&
        (IF_SEPARATOR(cmdf->command_end_idx))) {
            remove++;
            utils_cmd_dnode(sh, cmdf);
        }
    }
    if (remove > 0) {
        parser_dlim(sh);
    }
}

bool parser_find_sep(shell_t *sh)
{
    if (parser_check_len_max(sh) == false) {
        return false;
    }
    if (parser_del_more(sh) == false) {
        return false;
    }
    parser_dlim(sh);
    return true;
}

void parser_cmd_pcommand(char *s)
{
    for (; *s; s += 1) {
        *s = *(s + 1);
    }
}

void parser_cmd_pp(cmd_t *cmd)
{
    if (!cmd->commands) {
        return;
    }
    for (int i = 0; cmd->commands[i] != '\0'; i += 1) {
        if (!my_strncmp(PARSER_ARRAY[cmd->command_end_idx].parser_eof,
        &cmd->commands[i],
        strlen(PARSER_ARRAY[cmd->command_end_idx].parser_eof)) ||
        !my_strncmp(PARSER_ARRAY[cmd->command_end_idx].parser_end,
        &cmd->commands[i],
        strlen(PARSER_ARRAY[cmd->command_end_idx].parser_end))) {
            if (i > 0 && cmd->commands[i - 1] == '\\') {
                parser_cmd_pcommand(&cmd->commands[i - 1]);
            }
        }
    }
}

void parser_cmd_tmp_nrm(char *s)
{
    if (!s) {
        return;
    }
    for (; *s; s += 1) {
        if (*s == '\\') {
            parser_cmd_pcommand(s);
        }
    }
}