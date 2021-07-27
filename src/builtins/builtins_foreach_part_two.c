/*
** EPITECH PROJECT, 2021
** foreach part 2
** File description:
** .
*/

#include <stdio.h>
#include <builtins.h>

int count_args(char **argv)
{
    int i = 0;

    for (; argv[i]; i++);
    return i;
}

int check_parenthesis(char **argv)
{
    int argc = count_args(argv);
    int p = 0;

    if (argv[2][0] != '(' || argv[argc - 1][0] != ')') {
        fprintf(stderr, "foreach: Words not parenthesized.\n");
        return 1;
    } for (int i = 0; argv[i]; i++) {
        for (int y = 0; argv[i][y]; y++) {
            if (argv[i][y] == '(')
                p++;
            else if (argv[i][y] == ')')
                p--;
        }
    } if (p) {
        fprintf(stderr, "Too many )'s.\n");
        return 1;
    }
    return 0;
}

int check_variable(char **argv)
{
    char *str = argv[1];

    if ((str[0] >= 'z' || str[0] <= 'a') && (str[0] >= 'Z' || str[0] <= 'A')) {
        fprintf(stderr, "foreach: Variable name must begin with a letter.\n");
        return 1;
    }
    return 0;
}

int check_errors_foreach(int __attribute__ ((unused)) ac,
char **argv, shell_t *sh)
{
    int argc = count_args(argv);
    (void)sh;

    if (argc == 1) {
        fprintf(stderr, "foreach: Too few arguments.\n");
        return 1;
    }
    if (check_variable(argv))
        return 1;
    if (argc <= 2) {
        fprintf(stderr, "foreach: Too few arguments.\n");
        return 1;
    }
    return 0;
}