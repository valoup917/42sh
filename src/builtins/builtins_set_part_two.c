/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_set
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "just_shell.h"

static int builtins_set_utils_findc(char *s, char c)
{
    for (int i = 0; s[i]; i += 1) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int builtins_set_utils(char **array)
{
    bool check[2] = {false};
    int i = 0;

    if (!array[0]) {
        return 0;
    }
    i = builtins_set_utils_findc(array[0], '=');
    if (i != -1) {
        check[0] = true;
        if (array[0][i + 1] || array[1]) {
            check[1] = true;
        }
    } else if (array[1] && (i = builtins_set_utils_findc(array[1], '='))) {
        check[0] = true;
        if (array[1][i + 1] || array[2]) {
            check[1] = true;
        }
    } else {
        check[0] = true;
    }
    return (check[0] == false) ? false : true;
}

int builtins_set_utils_tmp(char **array, char *av[2])
{
    int i = 0;

    if (!array[0])
        return 0;
    i = builtins_set_utils_findc(array[0], '=');
    if (i != -1) {
        av[0] = strndup(array[0], i);
        if (array[0][i + 1]) {
            av[1] = strdup(&array[0][i + 1]);
        } else if (array[1])
            av[1] = strdup(array[1]);
    } else if (array[1] && (i = builtins_set_utils_findc(array[1], '='))) {
        av[0] = strdup(array[0]);
        if (array[1][i + 1]) {
            av[1] = strdup(&array[1][i + 1]);
        } else if (array[2])
            av[1] = strdup(array[2]);
    } else
        av[0] = strdup(array[0]);
    return (!av[0]) ? false : true;
}