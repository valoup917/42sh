/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_help
*/

#include <string.h>
#include <stdio.h>
#include "just_shell.h"
#include "man_help.h"

int help_case(char **av)
{
    for (int i = 0; DESCRIPTION_CASE[i].name != NULL; i += 1) {
        if (!strcmp(DESCRIPTION_CASE[i].name, av[1])) {
            printf("%s", DESCRIPTION_CASE[i].description);
            return 0;
        }
    }
    return 1;
}

int how_to_use_help(void)
{
    printf("%s", DESCRIPTION_CASE[0].description);
    printf("EXAMPLE : help 'setenv'\n");
    return 0;
}

int builtins_help(int ac, char **av, shell_t __attribute__ ((unused)) *sh)
{
    if (ac == 1) {
        if (sh->sh_wr)
            (void) how_to_use_help();
        return 0;
    } else if (ac == 2) {
        if (sh->sh_wr) {
            (void) help_case(av);
        }
        return 0;
    } else {
        if (sh->sh_wr) {
            how_to_use_help();
        }
        return 0;
    }
    return 1;
}