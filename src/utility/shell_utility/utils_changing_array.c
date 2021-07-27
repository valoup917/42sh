/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_changing_array
*/

#include <stdlib.h>
#include "just_shell.h"

static char **utils_tmp_replace_ar(alias_t *al, char **av)
{
    int i = sizeof_array_sh(&av[sizeof_array_sh(al->alias_find)]) +
    sizeof_array_sh(al->alias_redi);
    char **res = malloc(sizeof(char *) * (i + 2));

    if (!res) {
        return av;
    }
    res[0] = NULL;
    utils_array_cat(res, al->alias_redi);
    utils_array_cat(res, &av[sizeof_array_sh(al->alias_find)]);
    free(av);
    return res;
}

static char **utils_tmp_replace_arf(alias_t *al, char **av)
{
    int i = sizeof_array_sh(&av[sizeof_array_sh(al->alias_find)]) +
    sizeof_array_sh(al->alias_redi);
    char **res = malloc(sizeof(char *) * (i + 2));

    if (!res) {
        return av;
    }
    res[0] = NULL;
    utils_array_mcat(res, al->alias_redi);
    utils_array_mcat(res, &av[sizeof_array_sh(al->alias_find)]);
    free(av);
    return res;
}

char **utils_al_change(shell_t *sh, char **av, bool check)
{
    for (alias_t *al = sh->alias; al; al = al->next) {
        if (utils_compare_array(al->alias_find, av,
        sizeof_array_sh(al->alias_find))) {
            return (check) ? utils_tmp_replace_arf(al, av) :
            utils_tmp_replace_ar(al, av);
        }
    }
    return av;
}

alias_t *utils_al_rnode(alias_t *al, char **avo, char **avt)
{
    alias_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->next = NULL;
    res->prev = al;
    if (al) {
        al->next = res;
    }
    res->alias_find = avo;
    res->alias_redi = avt;
    return res;
}

alias_t *utils_al_lnode(alias_t *al, char **avo, char **avt)
{
    alias_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->next = al;
    res->prev = NULL;
    if (al) {
        al->prev = res;
    }
    res->alias_find = avo;
    res->alias_redi = avt;
    return res;
}