/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** gl_builtin_if
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void gl_builtin_if(char *str)
{
    char *buf = NULL;
    size_t len = 0;
    ssize_t read = 0;

    write(1, "if? ", 4);
    if ((read = getline(&buf, &len, stdin)) == -1) {
        free(buf);
        return;
    }
    buf[read - 1] = '\0';
    if (strcmp(buf, str) == 0)
        return;
    gl_builtin_if(str);
}