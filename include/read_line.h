/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line
*/

#ifndef READ_LINE_H_
#define READ_LINE_H_

#include <stddef.h>
#include "enable_lib.h"

static const char READ_LINE_ECS = '\e';

enum {
    KEY_ERROR = -1,
    KEY_CD = 4,
    KEY_TAB = '\t',
    KEY_CONTROLL = 12,
    KEY_DEL = 126,
    KEY_BACK = 127,
    KEY_UNKNOWN = 255,
    KEY_UP = 256,
    KEY_DOWN = 257,
    KEY_LEFT = 258,
    KEY_RIGHT = 259,
    START_HISTORY_LEN = 10,
    MAX_KEY_LEN = 16
};

typedef enum {
    CMP_CONTAINS = 0,
    CMP_EXACT
} compare_type_e;

typedef struct {
    char *key_pattern;
    int key_id;
} mykey_t;

typedef struct {
    char *history_line[START_HISTORY_LEN];
    int history_pos;
} history_t;

typedef struct {
    int fd;
    int current;
    history_t *h;
} rd_t;

typedef struct {
    int (*func)(rd_t *, int);
    int key_action;
} action_t;

#define TEST ((read_line->h->history_line)[read_line->h->history_pos])

int read_line_mouvements_left(rd_t *read_line,
int __attribute__ ((unused)) k);

int read_line_mouvements_right(rd_t *read_line,
int __attribute__ ((unused)) k);

int read_line_mouvement_down(rd_t *read_line, int __attribute__ ((unused)) k);

int read_line_mouvements_controll(rd_t *read_line,
int __attribute__ ((unused)) k);

int read_line_mouvement_remove(rd_t *read_line,
int __attribute__ ((unused)) k);

int read_line_mouvement_tab(rd_t *read_line, int __attribute__ ((unused)) k);

int read_line_mouvements_back(rd_t *read_line, int __attribute__ ((unused)) k);

int signal_read_key(const mykey_t *key);

void read_line_tmp_clear(rd_t *read_line, int len);

void read_line_tmp_putstr(const rd_t *read_line, const char *s);

void read_line_tmp_remove_char(char *s, int pos);

void read_line_tmp_put(const rd_t *read_line, char c);

bool read_line_add_char(rd_t *read_line, char c);

void read_line_tmp_remove_char(char *s, int pos);

void read_line_tmp_display(rd_t *read_line);

void move_history_down(history_t *h);

void free_history(void);

void init_history(rd_t *read_line);

void move_history_up(history_t *h);

int read_line_init(int fd, rd_t *read_line);

bool signal_char_init(void);

int signal_char_get(const mykey_t *key);

bool signal_char_terminated(void);

void read_line_mouvement_ret(rd_t *read_line);

int read_line_mouvements_char(rd_t *read_line, int __attribute__ ((unused)) k);

int read_line_key(rd_t *read_line, int __attribute__ ((unused)) k);

int read_line_mouvements_up(rd_t *read_line, int __attribute__ ((unused)) k);

#endif /* !READ_LINE_H_ */
