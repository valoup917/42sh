/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** str_is_digit
*/

#include <stdbool.h>

bool str_is_digit(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            return true;
    }
    return false;
}