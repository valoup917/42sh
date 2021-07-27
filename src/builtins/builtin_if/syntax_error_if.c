/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** syntax_error_if
*/

#include <stdbool.h>
#include "builtin_if.h"

int syntax_error_if(char **cmd, char *env[])
{
    int synt_error = syntax_cmd_if(cmd[1]);

    if (!cmd[1])
        printf("if: Too few arguments.\n");
    if (cmd[1] && !cmd[2]) {
        if (str_is_alpha(cmd[1]) == true)
            printf("if: Expression Syntax.\n");
        if (str_is_digit(cmd[1]) == true)
            printf("if: Empty if.\n");
    }
    if (cmd[1] && cmd[2] && !cmd[3]) {
        if (!strcmp(cmd[2], "then") && (str_is_alpha(cmd[1]) == true
        || synt_error != 1))
            printf("if: Expression Syntax.\n");
    }
    return 1;
}