/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line_add_char
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"

static bool read_line_tmp_add_char(char **s, int i, char c)
{
    char *result = NULL;

    if (i >= 0 && i > (int) strlen(*s)) {
        return false;
    }
    result = malloc(sizeof(char) * (strlen(*s) + 2));
    if (result == NULL) {
        return true;
    }
    strncpy(result, *s, i);
    result[i] = c;
    strcpy(result + i + 1, *s + i);
    free(*s);
    *s = result;
    return false;
}

bool read_line_add_char(rd_t *read_line, char c)
{
    return (read_line_tmp_add_char(&(TEST), read_line->current, c)) ?
    true : false;
}