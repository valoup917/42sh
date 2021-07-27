/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_alias_checking
*/

#include <stdlib.h>
#include <string.h>
#include "just_shell.h"
#include <stdio.h>

static int utils_strcmp_2d_array(char **s1, char **s2)
{
    int value = 0;
    size_t i = 0;

    for (; s1[i]; ++i) {
        if (s2[i] == NULL)
            return 1;
        value = strcmp(s1[i], s2[i]);
        if (!value)
            continue;
        return (value > 0) ? 1 : -1;
    }
    if (s2[i])
        return -1;
    return 0;
}

static char **utils_swap_remplace_value(char ***dest, char **src)
{
    char **cheat = utils_strdup_2d_array(src);
    char **free_array = *dest;

    *dest = cheat;
    utils_free_array(free_array);
    return *dest;
}

static void utils_swap_2d_array(char ***one, char ***two)
{
    char **tmp = utils_strdup_2d_array(*one);

    if (!tmp)
        return;
    if (!utils_swap_remplace_value(one, *two))
        return;
    if (!utils_swap_remplace_value(two, tmp))
        return;
    utils_free_array(tmp);
}

void utils_tri_alias(shell_t *alias)
{
    for (alias_t *one = alias->alias; one; one = one->next) {
        for (alias_t *two = one->next; two; two = two->next) {
            if (utils_strcmp_2d_array(two->alias_find, one->alias_find) == 1) {
                utils_swap_2d_array(&two->alias_find, &one->alias_find);
                utils_swap_2d_array(&two->alias_redi, &one->alias_redi);
            }
        }
    }
}

char **utils_remplace_alias(alias_t *alias, char **av)
{
    for (alias_t *pars = alias; pars; pars = pars->next) {
        if (!utils_strcmp_2d_array(pars->alias_find, av)) {
            return utils_strdup_2d_array(pars->alias_redi);
        }
    }
    return utils_strdup_2d_array(av);
}