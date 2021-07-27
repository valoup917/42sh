/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_alias_part_three
*/

#include <stdlib.h>
#include <string.h>
#include "just_shell.h"
#include "alias_bonus.h"
#include "parser.h"

char **utils_strdup_2d_array(char **array)
{
    size_t i = 0;
    char **result = malloc(sizeof(char *) * (sizeof_array_sh(array) + 1));

    if (!result)
        return NULL;
    for (; array[i] != NULL; ++i) {
        result[i] = malloc(sizeof(char) * (strlen(array[i]) + 1));
        if (!result[i])
            return NULL;
        strcpy(result[i], array[i]);
    }
    result[i] = NULL;
    return result;
}

static short utils_alias_bonus_fnd(char *s)
{
    for (short i = 0; ALIAS_BONUS[i] != NULL; i += 1) {
        if (!my_strcmp((char *) ALIAS_BONUS[i], s)) {
            return i;
        }
    }
    return -1;
}

bool utils_alias_bonus_set(shell_t *sh, char **av)
{
    char *r[2];
    lcl_t *lcl;

    if (utils_alias_bonus_fnd(av[0]) != -1) {
        lcl = utils_lcl_fnode(av[0], sh->lcl);
        if (lcl) {
            if (lcl->lcl_value)
                free(lcl->lcl_value);
            lcl->lcl_value = strdup(av[1]);
        } else {
            if ((r[0] = strdup(av[0])) == NULL) {
                return false;
            } if ((r[1] = strdup(av[1])) == NULL) {
                free(r[0]);
                return false;
            }
            sh->lcl = utils_lcl_al(r, sh->lcl);
        }
        return true;
    }
    return false;
}

bool utils_alias_bonus_exec(shell_t *sh, char *s)
{
    cmd_t *tmpc;
    list_t *tmpl;
    short i = utils_alias_bonus_fnd(s);
    lcl_t *lcl = utils_lcl_fnode(s, sh->lcl);
    int rt = 0;

    if (i != -1 && lcl != NULL) {
        tmpc = sh->commands;
        tmpl = sh->list;
        rt = sh->sh_rt;
        sh->commands = NULL;
        sh->list = NULL;
        sh_command_control(sh, strdup(lcl->lcl_value));
        sh->commands = tmpc;
        sh->list = tmpl;
        sh->sh_rt = rt;
        return true;
    }
    return false;
}

void free_sh_cmd(shell_t *sh)
{
    if (sh->commands) {
        utils_cmd_dlist(sh->commands);
    } else if (sh->list) {
        utils_linked_list_dlist(sh->list);
    }
    sh->commands = NULL;
    sh->list = NULL;
}