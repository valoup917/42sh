/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_free_history
*/

#include <stdlib.h>
#include <time.h>
#include "just_shell.h"

void utils_hs_dnode(previous_t *h)
{
    if (h->next) {
        h->next->prev = h->prev;
    }
    if (h->prev) {
        h->prev->next = h->next;
    }
    if (h->str) {
        free(h->str);
    }
    free(h);
}

void utils_hs_delexc(previous_t *h)
{
    int c = 0;

    for (; h && h->prev; h = h->prev) {
        c++;
    }
    c -= 50;
    if (c > 0) {
        for (previous_t *tmp; h && c > 0; c--) {
            tmp = h;
            h = h->next;
            utils_hs_dnode(tmp);
        }
    }
}

previous_t *utils_hs_ar(previous_t *h, char *s)
{
    previous_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->next = NULL;
    res->str = s;
    res->prev = h;
    res->id = 1;
    res->prev_date = 0;
    time(&res->prev_date);
    if (h != NULL) {
        res->id = h->id + 1;
        h->next = res;
    }
    utils_hs_delexc(res);
    return res;
}

previous_t *utils_hs_back(previous_t *p)
{
    for (; p && p->prev; p = p->prev);
    return p;
}

void utils_hs_dlist(previous_t *h)
{
    h = utils_hs_back(h);
    for (previous_t *tmp; h; free(tmp)) {
        tmp = h;
        h = h->next;
        if (tmp->str) {
            free(tmp->str);
        }
    }
}