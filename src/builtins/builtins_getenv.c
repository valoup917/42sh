/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_getenv
*/

#include <string.h>
#include "builtins.h"

int builtins_getenv_id(char **ar, char *s)
{
    int j = 0;

    if (!ar || !s) {
        return -1;
    }
    j = strlen(s);
    for (int i = 0; ar[i]; i += 1) {
        if (!my_strncmp(ar[i], s, j) && ar[i][j] == '=') {
            return i;
        }
    }
    return -1;
}

char *builtins_getenv(char **ar, char *s)
{
    int j = 0;

    if (!ar || !s) {
        return NULL;
    }
    j = strlen(s);
    for (int i = 0; ar[i]; i += 1) {
        if (!my_strncmp(ar[i], s, j) && ar[i][j] == '=') {
            return &ar[i][j + 1];
        }
    }
    return NULL;
}

char *builtins_find_getenv(char **ar, char *s)
{
    int j = 0;

    if (!ar || !s) {
        return NULL;
    }
    j = strlen(s);
    for (int i = 0; ar[i]; i += 1) {
        if (!my_strncmp(ar[i], s, j) && ar[i][j] == '=') {
            return ar[i];
        }
    }
    return NULL;
}

short check_builtins(char *s)
{
    if (!s) {
        return -1;
    }
    for (short i = 0; BUILTINS_ARRAY[i].name != NULL; i++) {
        if (my_strcmp(BUILTINS_ARRAY[i].name, s) == 0) {
            if (BUILTINS_ARRAY[i].func != NULL) {
                return i;
            }
        }
    }
    return -1;
}