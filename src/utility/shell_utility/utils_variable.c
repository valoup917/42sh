/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_variable
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "just_shell.h"
#include "parser.h"

static char *utils_parsing_get_variable(shell_t *sh,
char *s, char *n, int *i)
{
    char *res = NULL;
    char *vr = NULL;

    if (utils_parsing_cnt_opt(&s[*i + 1]) != -1) {
        res = utils_parsing_get_opt(&s[*i + 1]);
    }
    vr = utils_parsing_find_element(sh, (res) ? res : &s[*i + 1]);
    if (!vr) {
        if (n) {
            free(n);
        }
        return NULL;
    }
    *i += (res) ? utils_parsing_cnt_opt(&s[*i + 1]) + 1 :
    (int) strlen(&s[*i]) - 1;
    n = utils_realloc_string(n, vr);
    if (res) {
        free(res);
    }
    return n;
}

char *utils_parsing_cnt_opt_rt(shell_t *sh, char *s, char *n, int *i)
{
    char *vl = malloc(sizeof(char) * 4);

    if (!vl) {
        return n;
    }
    vl = memset(vl, '\0', 4);
    snprintf(vl, 4, "%d", sh->sh_rt);
    n = utils_realloc_string(n, vl);
    free(vl);
    if (!my_strncmp(&s[*i], "$?", 2)) {
        *i += 1;
    } else if (!my_strncmp(&s[*i], "${?}", 4)) {
        *i += 3;
    }
    return n;
}

char *utils_parsing_cnt_check(shell_t *sh, char *s, cmd_t *cmd)
{
    char *n = NULL;

    for (int i = 0; s[i]; i += 1) {
        if (!my_strncmp(&s[i], "$?", 2) || !my_strncmp(&s[i], "${?}", 4)) {
            n = utils_parsing_cnt_opt_rt(sh, s, n, &i);
        } else if (s[i] == '$') {
            n = utils_parsing_get_variable(sh, s, n, &i);
        } else {
            n = utils_parsing_end_of_line(n, s[i]);
        }
    }
    free(cmd->commands);
    cmd->commands = n;
    return n;
}

char *utils_get_variable(shell_t *sh, cmd_t *cmd)
{
    if (PARSER_ARRAY[cmd->command_end_idx].id == DELIMIT_SQUOTE) {
        return cmd->commands;
    }
    if (cmd->commands == NULL) {
        return NULL;
    }
    if (strstr(cmd->commands, "$")) {
        cmd->commands = utils_parsing_cnt_check(sh, cmd->commands, cmd);
    }
    if (cmd->commands && !my_strncmp(cmd->commands, "~", 1)) {
        return util_get_environ_path(cmd);
    }
    return cmd->commands;
}