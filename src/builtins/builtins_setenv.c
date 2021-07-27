/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_setenv
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "builtins.h"

static bool builtins_env_check(char *s)
{
    for (int i = 0; s[i]; i += 1) {
        if ((s[i] >= 0 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64) ||
        (s[i] >= 91 && s[i] <= 94) || s[i] == 96 || s[i] >= 123) {
            return false;
        }
    }
    return true;
}

static int builtins_fsetenv(shell_t *sh, char **av, char *s, int i)
{
    memset(s, '\0', i);
    strcat(s, av[1]);
    strcat(s, "=");
    if (av[2] != NULL) {
        strcat(s, av[2]);
    }
    if (!my_strcmp(av[1], "PATH")) {
        utils_free_array(sh->sh_path);
        sh->sh_path = my_str_to_word_array_gl(av[2], ':');
    }
    return 0;
}

static int builtins_set_find_info(int i, char **av, shell_t *sh)
{
    int j = 0;
    char *s = builtins_find_getenv(sh->sh_array, av[1]);

    if (!s) {
        s = malloc(sizeof(char) * i);
        if (!s) {
            return -1;
        }
        sh->sh_array = utils_alloc_array(sh->sh_array, s);
        if (!s) {
            return -1;
        }
        return builtins_fsetenv(sh, av, s, i);
    } else {
        j = builtins_getenv_id(sh->sh_array, av[1]);
        sh->sh_array[j] = realloc(sh->sh_array[j], sizeof(char) * i);
        if (!sh->sh_array[j])
            return -1;
        return builtins_fsetenv(sh, av, sh->sh_array[j], i);
    }
    return 0;
}

static int builtins_fsetenv_thread(char **av, shell_t *sh)
{
    int i = 0;

    if (builtins_env_check(av[1]) == false) {
        if (sh->sh_wr) {
            printf(
            "setenv: Variable name must contain alphanumeric characters.\n");
        }
        return 1;
    }
    i = strlen(av[1]) + ((av[2] != NULL) ? strlen(av[2]) : 0) + 2;
    return builtins_set_find_info(i, av, sh);
}

int builtins_setenv(int ac, char **av, shell_t *sh)
{
    if (ac == 1) {
        return builtins_env(ac, av, sh);
    } else if (ac >= 4) {
        if (sh->sh_wr) {
            fprintf(stdout, TOO_MANY_ARG, av[0]);
        }
        return 1;
    }
    return builtins_fsetenv_thread(av, sh);
}