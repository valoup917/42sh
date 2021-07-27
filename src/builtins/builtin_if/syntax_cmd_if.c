/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** syntax_cmd_if
*/

#include <stdbool.h>
#include "builtin_if.h"

int syntax_cmd_if(char *str)
{
    int len = strlen(str);

    for (int i = 0; str[i]; i++) {
        if ((str[0] == '(' && str[len - 1] == ')')
        || (str[0] == '(' && str[len - 1] == ')'
        && (str[i] == '=' && str[i + 1] == '=')
        && (char_is_alpha(str[i]) == true || char_is_digit(str[i]) == true)))
            return 1;
    }
    return 0;
}