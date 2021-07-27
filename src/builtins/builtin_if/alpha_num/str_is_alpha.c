/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** str_is_alpha
*/

#include <stdbool.h>

bool str_is_alpha(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= 'a' && str[i] <= 'z'))
            return true;
    }
    return false;
}