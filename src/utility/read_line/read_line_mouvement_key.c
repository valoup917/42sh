/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line_mouvement_key
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "read_line.h"
#include "action_glob.h"

int read_line_mouvements_up(rd_t *read_line, int __attribute__ ((unused)) k)
{
    read_line_tmp_clear(read_line, -1);
    move_history_up(read_line->h);
    read_line_tmp_putstr(read_line, TEST);
    read_line->current = strlen(TEST);
    return 0;
}

const char *read_line_line(int fd, const mykey_t *key)
{
    rd_t read_line;
    int k = 0;

    if (read_line_init(fd, &read_line)) {
        return NULL;
    }
    signal_char_init();
    while ((k = signal_char_get(key)) != '\n' && k != KEY_CD) {
        if (read_line_key(&read_line, k)) {
            signal_char_terminated();
            return NULL;
        }
    }
    read_line_mouvement_ret(&read_line);
    signal_char_terminated();
    if (k == KEY_CD) {
        return NULL;
    }
    return (read_line.h->history_line)[read_line.h->history_pos];
}

int read_line_key(rd_t *read_line, int __attribute__ ((unused)) k)
{
    for (int i = 0; ACTION_GLOBAL[i].func != NULL; i += 1) {
        if (ACTION_GLOBAL[i].key_action == k) {
            return ACTION_GLOBAL[i].func(read_line, k);
        }
    }
    if (k != KEY_UNKNOWN && k != KEY_ERROR) {
        return read_line_mouvements_char(read_line, k);
    }
    return 0;
}