/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_unsetenv
*/

#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "builtins.h"

static int builtins_unsetenv_thread(char **av, shell_t *sh)
{
    char *s = NULL;

    for (int i = 1; av[i]; i += 1) {
        s = builtins_find_getenv(sh->sh_array, av[i]);
        if (s) {
            sh->sh_array = utils_array_delete_node(sh->sh_array, s);
            if (!sh->sh_array)
                return -1;
            if (!my_strcmp(av[i], "PATH")) {
                utils_free_array(sh->sh_path);
                sh->sh_path = NULL;
            }
        }
    }
    return 0;
}

int builtins_unsetenv(int ac, char **av, shell_t *sh)
{
    if (ac < 2) {
        if (sh->sh_wr) {
            fprintf(stdout, TOO_FEW_ARG, av[0]);
        }
        return 1;
    }
    return builtins_unsetenv_thread(av, sh);
}

int builtins_builtins(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh)
{
    if (!sh->sh_wr)
        return 0;
    for (short i = 0; BUILTINS_ARRAY[i].name != NULL; i += 1) {
        printf("- %s\n", BUILTINS_ARRAY[i].name);
    }
    return 0;
}