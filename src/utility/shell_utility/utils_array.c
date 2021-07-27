/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_array
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "just_shell.h"

char *utils_realloc_string(char *s, char *d)
{
    if (!s) {
        s = malloc(sizeof(char));
        if (!s) {
            return NULL;
        }
        *s = '\0';
    }
    if (!d) {
        return s;
    }
    s = realloc(s, sizeof(char) * ((strlen(s) + strlen(d)) + 1));
    s = strcat(s, d);
    return s;
}

char *utils_parsing_end_of_line(char *msg, char c)
{
    char a[2];

    a[0] = c;
    a[1] = '\0';
    return utils_realloc_string(msg, a);
}

int utils_parsing_cnt_opt(char *s)
{
    if (*s != '{') {
        return -1;
    }
    for (int i = 0; s[i]; i += 1) {
        if (s[i] == '}') {
            return i;
        }
    }
    return -1;
}

char *utils_parsing_get_opt(char *s)
{
    int i = 0;
    char *res = malloc(sizeof(char) * utils_parsing_cnt_opt(s) + 1);

    if (!res) {
        return NULL;
    }
    for (; s[i + 1] && s[i + 1] != '}'; i += 1) {
        res[i] = s[i + 1];
    }
    res[i] = '\0';
    return res;
}

char *utils_parsing_find_element(shell_t *sh, char *s)
{
    lcl_t *lc = sh->lcl;
    char *check = builtins_getenv(sh->sh_array, s);

    if (check) {
        return check;
    }
    for (; lc; lc = lc->next) {
        if (!my_strcmp(lc->lcl_name, s)) {
            return lc->lcl_value;
        }
    }
    return NULL;
}