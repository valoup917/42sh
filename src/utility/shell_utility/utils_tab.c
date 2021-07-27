/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_tab
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "enable_lib.h"

bool utils_compare_array(char **ar, char **dp, int n)
{
    int i = 0;

    for (; ar[i] && dp[i] && i < n; i += 1) {
        if (my_strcmp(ar[i], dp[i])) {
            return false;
        }
    }
    return (i < n) ? false : true;
}

int sizeof_array_sh(char **ar)
{
    int i = 0;

    if (!ar) {
        return -1;
    }
    for (; ar[i]; i += 1);
    return i;
}

char **utils_alloc_array(char **ar, char *s)
{
    int i = sizeof_array_sh(ar);

    if (i == -1) {
        return NULL;
    }
    ar = realloc(ar, sizeof(char *) * (i + 2));
    if (!ar) {
        return NULL;
    }
    ar[i] = s;
    ar[i + 1] = NULL;
    return ar;
}

bool utils_free_array(char **ar)
{
    if (!ar) {
        return false;
    }
    for (int i = 0; ar[i]; i += 1) {
        free(ar[i]);
    }
    free(ar);
    return true;
}

char **utils_array_delete_node(char **ar, char *s)
{
    int i = 0;
    int j = sizeof_array_sh(ar);

    if (i == -1) {
        return NULL;
    }
    for (; ar[i] && ar[i] != s; i += 1);
    for (; ar[i]; i += 1) {
        ar[i] = ar[i + 1];
    }
    ar[i] = NULL;
    free(s);
    ar = realloc(ar, sizeof(char *) * j);
    return ar;
}