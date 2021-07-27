/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** builtins_if
*/

#include <string.h>
#include "builtin_if.h"

int builtins_if(char **cmd, char *env[])
{
    int error = syntax_error_if(cmd, env);
    int synt = syntax_cmd_if(cmd[1]);

    if (cmd[1] && cmd[2] && !cmd[3]) {
        if (!strcmp(cmd[2], "then") && synt == 1)
            gl_builtin_if("endif");
    }
    if (error == 1)
        return 2;
    return 1;
}