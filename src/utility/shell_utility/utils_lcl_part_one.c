/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_lcl_part_one
*/

#include <stdlib.h>
#include <string.h>
#include "just_shell.h"

lcl_t *utils_lcl_ar(char *r[2], lcl_t *lcl)
{
    lcl_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->next = NULL;
    res->next = lcl;
    if (lcl) {
        lcl->next = res;
    }
    res->lcl_name = r[0];
    res->lcl_value = r[1];
    return res;
}

lcl_t *utils_lcl_al(char *r[2], lcl_t *lcl)
{
    lcl_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->next = lcl;
    res->prev = NULL;
    if (lcl) {
        lcl->prev = res;
    }
    res->lcl_name = r[0];
    res->lcl_value = r[1];
    return res;
}

lcl_t *utils_lcl_fnode(char *s, lcl_t *lcl)
{
    for (; lcl; lcl = lcl->next) {
        if (!my_strcmp(lcl->lcl_name, s)) {
            return lcl;
        }
    }
    return NULL;
}

void utils_lcl_dnode(lcl_t *lcl)
{
    if (lcl->next) {
        lcl->next->prev = lcl->prev;
    }
    if (lcl->prev) {
        lcl->prev->next = lcl->next;
    }
    if (lcl->lcl_name) {
        free(lcl->lcl_name);
    }
    if (lcl->lcl_value) {
        free(lcl->lcl_value);
    }
    free(lcl);
}

void utils_lcl_dlist(lcl_t *lcl)
{
    for (lcl_t *tmp; lcl; utils_lcl_dnode(tmp)) {
        tmp = lcl;
        lcl = lcl->next;
    }
}