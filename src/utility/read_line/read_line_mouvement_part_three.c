/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line_mouvement_part_three
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "read_line.h"

int read_line_mouvement_remove(rd_t *read_line, int __attribute__ ((unused)) k)
{
    read_line_tmp_remove_char(TEST, read_line->current);
    read_line_tmp_display(read_line);
    return 0;
}

int read_line_mouvement_down(rd_t *read_line, int __attribute__ ((unused)) k)
{
    read_line_tmp_clear(read_line, -1);
    move_history_down(read_line->h);
    read_line_tmp_putstr(read_line, TEST);
    read_line->current = strlen(TEST);
    return 0;
}

void read_line_free(void)
{
    free_history();
}

int read_line_init(int fd, rd_t *read_line)
{
    init_history(read_line);
    free(TEST);
    TEST = malloc(sizeof(char));
    if (TEST == NULL) {
        return 1;
    }
    (TEST)[0] = '\0';
    read_line->current = 0;
    read_line->fd = fd;
    return 0;
}

void read_line_mouvement_ret(rd_t *read_line)
{
    while (read_line->current < (int) strlen(TEST)) {
        read_line_mouvements_right(read_line, KEY_RIGHT);
    }
    read_line_tmp_put(read_line, '\n');
}