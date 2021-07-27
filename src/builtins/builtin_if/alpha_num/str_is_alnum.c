/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** str_is_alnum
*/

#include <stdbool.h>

bool str_is_alnum(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= '0' && str[i] <= '9'))
            return true;
    }
    return false;
}