/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** char_is_digit
*/

#include <stdbool.h>

bool char_is_digit(char c)
{
    return ((c >= '0' && c <= '9') ? true : false);
}