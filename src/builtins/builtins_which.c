/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_which
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "builtins.h"

void print_2d_array(char **array)
{
    for (int i = 0; array[i] != NULL; ++i) {
        printf("%s", array[i]);
        if (array[i + 1] != NULL)
            putchar(' ');
    }
    putchar('\n');
}

int compare_str_2d_array(char *str, char **array)
{
    char **array_2 = my_str_to_word_array_gl(str, ' ');

    if (sizeof_array_sh(array) != sizeof_array_sh(array_2))
        return 1;
    for (int i = 0; array[i] != NULL; ++i)
        if (strcmp(array_2[i], array[i]))
            return 1;
    utils_free_array(array_2);
    return 0;
}

static bool search_alias(char *av, alias_t *alias)
{
    for (alias_t *count = alias; count; count = count->next)
        if (!compare_str_2d_array(av, count->alias_find)) {
            printf("%s: \t aliased to ", av);
            print_2d_array(count->alias_redi);
            return true;
        }
    return false;
}

static int builtins_which_rt_finder(char **av, shell_t *sh)
{
    char *s = NULL;
    bool check = false;

    for (int i = 1; av[i]; i += 1) {
        if (search_alias(av[i], sh->alias)) {
            check = true;
            continue;
        }
        if (check_builtins(av[i]) != -1) {
            printf(IS_BUILTIN, av[i]);
            check = true;
        } else if ((s = sh_path_env(sh, av[i])) != NULL) {
            printf("%s\n", s);
            free(s);
            check = true;
        } else {
            fprintf(stderr, ERROR_NOT_FOUND, av[i]);
        }
    }
    return (check) ? 0 : 1;
}

int builtins_which(int __attribute__ ((unused)) ac, char **av, shell_t *sh)
{
    if (ac < 2) {
        if (sh->sh_wr) {
            fprintf(stdout, TOO_FEW_ARG, av[0]);
        }
        return 1;
    }
    if (!sh->sh_wr) {
        return 0;
    }
    return builtins_which_rt_finder(av, sh);
}