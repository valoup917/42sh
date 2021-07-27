/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser_end
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "parser.h"

bool parser_get_end(char *s, char *e, int *n)
{
    for (; s[*n] != '\0'; *n += 1) {
        if (!(*n > 0 && s[*n - 1] == '\\') &&
        !my_strncmp(&s[*n], e, strlen(e))) {
            return true;
        }
    }
    return false;
}

bool parser_cant_delimit(shell_t *sh, char *s, int *i, int id)
{
    int j = 0;

    *i += strlen(PARSER_ARRAY[id].parser_end);
    j = *i;
    if (GET_MY_TYPE(id) == DELIMIT_GET || (IF_SEPARATOR(id))) {
        sh->commands = utils_cmd_radd(sh->commands, NULL, id);
    } else if (GET_MY_TYPE(id) == DELIMIT_DELIMITER) {
        if (parser_get_end(s, PARSER_ARRAY[id].parser_eof, i)) {
            sh->commands =
            utils_cmd_radd(sh->commands, strndup(&s[j], *i - j), id);
            *i += strlen(PARSER_ARRAY[id].parser_eof);
        } else {
            fprintf(stdout, "Unmatched '%s'.\n", PARSER_ARRAY[id].parser_eof);
            return false;
        }
    }
    return true;
}

bool sh_parser(shell_t *sh, char *s, bool check)
{
    int i = 0;
    int j = 0;
    int id = 0;

    for (sh->commands = NULL; s[i]; ) {
        for (j = i; s[i] && (id = parser_end_of_type(s, &i)) ==
        DELIMIT_WITHOUT; i += 1);
        if (i - j > 0) {
            sh->commands = utils_cmd_radd(sh->commands, strndup(&s[j], i - j),
            DELIMIT_WITHOUT);
        }
        if (id != DELIMIT_WITHOUT &&
        parser_cant_delimit(sh, s, &i, id) == false)
            return false;
    }
    sh->commands = utils_cmd_move_back(sh->commands);
    sh->commands = parser_cmd_comment(sh->commands);
    parser_cmd_bslash(sh->commands);
    parser_cmd_dquote(sh->commands);
    (check == true) ? parser_cmd_hist(sh, sh->commands) : 0;
    return true;
}

void sh_parser_linked(shell_t *sh)
{
    cmd_t *tmp = sh->commands;

    sh->list = NULL;
    if (tmp) {
        for (sh->list = utils_linked_list_ar(sh->list, tmp, DELIMIT_SEPARATOR);
        tmp; tmp = tmp->next) {
            if (tmp->prev && tmp->prev->command_end_idx != DELIMIT_WITHOUT &&
            (IF_SEPARATOR(tmp->prev->command_end_idx))) {
                sh->list = utils_linked_list_ar(
                sh->list, tmp, tmp->prev->command_end_idx);
                utils_cmd_pnode(tmp->prev);
            }
        }
    }
    sh->list = utils_linked_list_move_back(sh->list);
    sh->commands = NULL;
}

bool sh_parser_global(shell_t *sh, char *s)
{
    if (sh_parser(sh, s, true) == false || parser_find_sep(sh) == false) {
        sh->commands = utils_cmd_move_back(sh->commands);
        utils_cmd_dlist(sh->commands);
        sh->commands = NULL;
        return false;
    }
    sh_parser_linked(sh);
    if (sh_parser_pipe(sh) == false) {
        return false;
    }
    if (parser_bg(sh) == false) {
        free_sh_cmd(sh);
        return false;
    }
    return true;
}