/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line_mouvement_part_two
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

void read_line_tmp_display(rd_t *read_line)
{
    int current = read_line->current;

    read_line_tmp_clear(read_line, -1);
    read_line_tmp_putstr(read_line, TEST);
    read_line->current = strlen(TEST);
    while (read_line->current > current) {
        read_line_mouvements_left(read_line, KEY_LEFT);
    }
}

int read_line_mouvements_back(rd_t *read_line, int __attribute__ ((unused)) k)
{
    if (read_line->current > 0) {
        read_line_tmp_remove_char(TEST, read_line->current - 1);
        read_line_mouvements_left(read_line, KEY_LEFT);
        read_line_tmp_display(read_line);
    }
    return 0;
}

int read_line_mouvements_right(rd_t *read_line, int __attribute__ ((unused)) k)
{
    if (read_line->current < (int) strlen(TEST)) {
        read_line_tmp_put(read_line,
        ((read_line->h->history_line)
        [read_line->h->history_pos])[read_line->current]);
        read_line->current += 1;
    }
    return 0;
}

int read_line_mouvements_char(rd_t *read_line, int __attribute__ ((unused)) k)
{
    if (read_line_add_char(read_line, (char) k)) {
        return 1;
    }
    read_line_tmp_display(read_line);
    read_line_mouvements_right(read_line, KEY_RIGHT);
    return 0;
}

int read_line_mouvements_controll(rd_t *read_line,
int __attribute__ ((unused)) k)
{
    printf("\e[1;1H\e[2J");
    fflush(stdout);
    read_line_tmp_display(read_line);
    return 0;
}
