/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** char_is_alnum
*/

#include <stdbool.h>

bool char_is_alnum(char c)
{
    return (char_is_alpha(c) || char_is_digit(c));
}