/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_alias
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "just_shell.h"

static void builtins_alias_view(char **array)
{
    int j = sizeof_array_sh(array);

    if (j > 1) {
        printf("(");
    }
    for (int i = 0; array[i] != NULL; i += 1) {
        printf("%s", array[i]);
        if (array[i + 1] != NULL) {
            printf(" ");
        }
    }
    if (j > 1) {
        printf(")");
    }
}

static bool builtins_alias_remplace(alias_t *sh, char **av)
{
    for (alias_t *pars = sh; pars; pars = pars->next) {
        if (!compare_str_2d_array(av[1], pars->alias_find)) {
            utils_free_array(pars->alias_redi);
            pars->alias_redi = utils_remplace_alias(sh, &av[2]);
            return true;
        }
    }
    return false;
}

static void builtins_alias_get_view(shell_t *sh)
{
    alias_t *al = sh->alias;

    for (; al && al->next; al = al->next);
    for (; al; al = al->prev) {
        builtins_alias_view(al->alias_find);
        printf("\t");
        builtins_alias_view(al->alias_redi);
        printf("\n");
    }
}

static int builtins_alias_thread(char **av, shell_t *sh, bool args)
{
    char **array = NULL;

    if (builtins_alias_remplace(sh->alias, av) == false\
    && utils_alias_bonus_set(sh, &av[1]) == false) {
        if (args == true)
            array = my_str_to_word_array_gl(av[2], ' ');
        else
            array = utils_strdup_2d_array(&av[2]);
        if (!array)
            return -1;
        array = utils_al_change(sh, array, true);
        sh->alias = utils_al_lnode(sh->alias,
        my_str_to_word_array_gl(av[1], ' '), array);
        utils_tri_alias(sh);
    }
    return 0;
}

int builtins_alias(int ac, char **av, shell_t *sh)
{
    if (ac == 2) {
        return 1;
    }
    if (ac > 2) {
        return builtins_alias_thread(av, sh, (ac == 3));
    } else {
        if (sh->sh_wr) {
            builtins_alias_get_view(sh);
        }
    }
    return 0;
}