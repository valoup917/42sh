/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_set
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"

static int builtins_tmp_set(char **av, shell_t *sh)
{
    char *args[2] = {NULL};
    lcl_t *lcl;

    if (builtins_set_utils_tmp(av, args) == false)
        return 1;
    if (!args[0] || strlen(args[0]) <= 0) {
        free(args[0]);
        return 1;
    }
    lcl = utils_lcl_fnode(args[0], sh->lcl);
    if (lcl) {
        free(lcl->lcl_name);
        if (lcl->lcl_value) {
            free(lcl->lcl_value);
        }
        lcl->lcl_name = args[0];
        lcl->lcl_value = args[1];
    } else {
        sh->lcl = utils_lcl_al(args, sh->lcl);
    }
    return 0;
}

static void builtins_set_tmp_show(shell_t *sh)
{
    lcl_t *lcl = sh->lcl;

    for (; lcl && lcl->prev; lcl = lcl->prev);
    for (; lcl; lcl = lcl->next) {
        printf("%s\t%s\n", lcl->lcl_name, lcl->lcl_value);
    }
}

int builtins_set(int __attribute__ ((unused)) ac, char **av, shell_t *sh)
{
    if (ac == 2) {
        return 1;
    }
    if (builtins_set_utils(&av[1]) == true) {
        return builtins_tmp_set(&av[1], sh);
    } else {
        if (sh->sh_wr) {
            builtins_set_tmp_show(sh);
        }
    }
    return 1;
}
