/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line_mouvements
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "read_line.h"

void read_line_tmp_remove_char(char *s, int pos)
{
    bool sswitch = false;

    for (int i = 0; i < (int) strlen(s); i += 1) {
        if (i == pos) {
            sswitch = true;
        }
        s[i] = s[i + sswitch];
    }
}

void read_line_tmp_put(const rd_t *read_line, char c)
{
    write(read_line->fd, &c, 1);
}

void read_line_tmp_putstr(const rd_t *read_line, const char *s)
{
    write(read_line->fd, s, strlen(s));
}

int read_line_mouvements_left(rd_t *read_line, int __attribute__ ((unused)) k)
{
    if (read_line->current > 0) {
        read_line_tmp_put(read_line, '\b');
        read_line->current -= 1;
    }
    return 0;
}

void read_line_tmp_clear(rd_t *read_line, int len)
{
    if (len == -1) {
        len = (int) strlen(TEST) + 1;
    }
    for (; read_line->current < len; read_line->current += 1) {
        read_line_tmp_put(read_line, ' ');
    }
    for (; read_line->current > 0; read_line->current -= 1) {
        read_line_tmp_putstr(read_line, "\b \b");
    }
}