/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_tab_part_two
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "just_shell.h"

char **utils_array_copy(char **ar)
{
    char **res = NULL;
    int i = 0;
    int j = sizeof_array_sh(ar);

    if (j == -1) {
        return NULL;
    }
    res = malloc(sizeof(char *) * (j + 1));
    if (!res) {
        return NULL;
    }
    for (; i < j; i += 1) {
        res[i] = strdup(ar[i]);
    }
    res[i] = NULL;
    return res;
}

void utils_array_cat(char **ar, char **dp)
{
    int i = 0;
    int j = 0;

    for (; ar[i]; i += 1);
    for (; dp[j]; ar[i++] = dp[j++]);
    ar[i] = NULL;
}

void utils_array_mcat(char **ar, char **dp)
{
    int i = 0;
    int j = 0;

    for (; ar[i]; i += 1);
    for (; dp[j];ar[i++] = strdup(dp[j++]));
    ar[i] = NULL;
}

void util_al_del_node(alias_t *al)
{
    if (al->next) {
        al->next->prev = al->prev;
    }
    if (al->prev) {
        al->prev->next = al->next;
    }
    utils_free_array(al->alias_find);
    utils_free_array(al->alias_redi);
    free(al);
}

void utils_al_del_list(alias_t *al)
{
    for (alias_t *tmp; al; util_al_del_node(tmp)) {
        tmp = al;
        al = al->next;
    }
}