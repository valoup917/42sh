/*
** EPITECH PROJECT, 2021
** repeat
** File description:
** .
*/

#include <stdio.h>
#include <builtins.h>

static unsigned int count_command(char **argv)
{
    unsigned int a = 0;

    for (unsigned int i = 2; argv[i]; i++)
        a++;
    return a;
}

static int error_handling_repeat(int ac, char **argv, shell_t *sh)
{
    char *str = NULL;

    if (ac <= 2) {
        if (sh->sh_wr)
            fprintf(stderr, TOO_FEW_ARG, argv[0]);
        return 1;
    }
    str = argv[1];
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (sh->sh_wr)
                fprintf(stderr, "%s: Badly formed number.\n", argv[0]);
            return 1;
        }
    }
    return 0;
}

int builtins_repeat(int ac, char **argv, shell_t *sh)
{
    unsigned int a = 0;
    char **tmp = NULL;
    int rt = 0;

    if (error_handling_repeat(ac, argv, sh))
        return 1;
    tmp = malloc(sizeof(char *) * ((count_command(argv)) + 10));
    for (unsigned int i = 2; argv[i]; i++) {
        tmp[a] = argv[i];
        a++;
        tmp[a] = NULL;
    }
    for (int i = 0; i != atoi(argv[1]); i++) {
        if (sh->sh_wr)
            rt = executable(tmp, sh);
    }
    return rt;
}