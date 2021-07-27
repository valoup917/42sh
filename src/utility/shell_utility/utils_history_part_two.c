/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_history_part_two
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"

static char *utils_hs_gn(previous_t *h, char *s)
{
    unsigned n = atoi(s);

    if (!h || h->id < n) {
        return NULL;
    }
    for (; h; h = h->prev) {
        if (h->id == n) {
            return h->str;
        }
    }
    return NULL;
}

static char *utils_hs_past(previous_t *h, char *s)
{
    unsigned i = 1;
    unsigned n = atoi(&s[i]);

    if (!h) {
        return NULL;
    }
    for (; h; h = h->prev) {
        if ((i++) == n) {
            return h->str;
        }
    }
    return NULL;
}

static char *utils_hs_val(previous_t *h, char *s)
{
    size_t j = strlen(s);

    if (!h) {
        return NULL;
    }
    for (; h; h = h->prev) {
        if (!my_strncmp(h->str, s, j)) {
            return h->str;
        }
    }
    return NULL;
}

static char *utils_hs_last(previous_t *h)
{
    return (!h) ? NULL : h->str;
}

char *utils_hs(shell_t *sh, char *s)
{
    char *res = NULL;
    previous_t *h = sh->history;

    if (!s || !h || my_strncmp(s, "!", 1)) {
        return NULL;
    }
    res = s + 1;
    if (*res == '!') {
        return utils_hs_last(h->prev);
    }
    if (*res == '-') {
        return utils_hs_past(h->prev, res);
    }
    if (*res >= '0' && *res <= '9') {
        return utils_hs_gn(h->prev, res);
    }
    return utils_hs_val(h->prev, res);
}