/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** char_is_alpha
*/

#include <stdbool.h>

bool char_is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') ? true : false);
}