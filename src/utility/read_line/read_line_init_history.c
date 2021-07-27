/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** history
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "macro_history_two.h"

static void read_line_move_line(history_t *h)
{
    int i = 0;

    free((h->history_line)[i]);
    for (; i + 1 < START_HISTORY_LEN; i += 1) {
        (h->history_line)[i] = (h->history_line)[i + 1];
    }
    (h->history_line)[START_HISTORY_LEN - 1] = NULL;
}

void read_line_free_history(void)
{
    history.history_pos = 0;
    if (check) {
        return;
    }
    for (int i = 0; i < START_HISTORY_LEN; i += 1) {
        free((history.history_line)[i]);
        (history.history_line)[i] = 0;
    }
}

void read_line_init_history(rd_t *read_line)
{
    if (check) {
        memset(&history, 0, sizeof(history_t));
        check = false;
    } else {
        (history.history_pos + 1 < START_HISTORY_LEN) ?
        history.history_pos += 1 : read_line_move_line(&history);
    }
    read_line->h = &history;
}
