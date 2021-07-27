/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser_sep_part_two
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

void parser_cmd_bslash(cmd_t *cmd)
{
    for (; cmd; cmd = cmd->next) {
        if (GET_MY_TYPE(cmd->command_end_idx) == DELIMIT_DELIMITER) {
            parser_cmd_pp(cmd);
        }
        if (cmd->command_end_idx == DELIMIT_WITHOUT) {
            parser_cmd_tmp_nrm(cmd->commands);
        }
    }
}

cmd_t *parser_cmd_comment(cmd_t *cmd)
{
    for (cmd_t *tmp = cmd; tmp; tmp = tmp->next) {
        if (tmp->commands && GET_MY_TYPE(tmp->command_end_idx) ==
        DELIMIT_NORMAL && !my_strncmp(tmp->commands, "#", 1)) {
            if (tmp->prev) {
                tmp->prev->next = NULL;
            }
            utils_cmd_dlist(tmp);
            if (tmp == cmd) {
                return NULL;
            }
            return cmd;
        }
    }
    return cmd;
}

char *parser_sep_fquotes_tmp(char *s)
{
    for (short i = 0; QUOTE_ARRAY[i].at != NULL; i++) {
        if (!my_strncmp(s, QUOTE_ARRAY[i].at, strlen(QUOTE_ARRAY[i].at))) {
            return QUOTE_ARRAY[i].my;
        }
    }
    return NULL;
}

void parser_sep_tmp_replace_quotes(char *s, char c)
{
    unsigned i = 1;

    for (*s = c; s[i]; i += 1) {
        s[i] = s[i + 1];
    }
}

void parser_sep_tmp_quotes_threat(char *s)
{
    char *new;

    for (int i = 0; s[i]; i += 1) {
        new = NULL;
        new = parser_sep_fquotes_tmp(&s[i]);
        if (new) {
            parser_sep_tmp_replace_quotes(&s[i], new[0]);
        }
    }
}
