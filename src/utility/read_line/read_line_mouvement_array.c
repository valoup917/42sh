/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** read_line_mouvement_array
*/

#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <glob.h>
#include "read_line.h"

static char *read_line_tmp_ptr(char *c, char *f)
{
    char *nw = NULL;
    char *nv = c;
    size_t n = 0;

    for (; nv != f && (nv == c || (*nv != ' ' &&
    *nv != '\t' && *nv != '"' && *nv != '\'')); nv -= 1);
    if (nv != c && (*nv == ' ' || *nv == '\t' || *nv == '"' || *nv == '\'')) {
        nv += 1;
    }
    n = (c - nv);
    if (*nv == '\0' || n <= 0)
        return NULL;
    nw = malloc(sizeof(char) * (n + 2));
    if (!nw) {
        return NULL;
    }
    memset(nw, '\0', n + 2);
    strncpy(nw, nv, n);
    strcat(nw, "*");
    return nw;
}

static void read_line_filler(rd_t *read_line, char *s, glob_t *g)
{
    unsigned i = strlen(s) - 1;

    for (; g->gl_pathv[0][i] != '\0'; i += 1) {
        read_line_tmp_put(read_line, g->gl_pathv[0][i]);
        read_line_add_char(read_line, g->gl_pathv[0][i]);
        read_line->current += 1;
    }
    read_line_tmp_display(read_line);
}

static void read_line_max_filler(rd_t *read_line, glob_t *g)
{
    unsigned i = 0;
    unsigned prec = 0;

    printf("\n");
    for (i = 0; g->gl_pathv[i] != NULL; i += 1) {
        if (strlen(g->gl_pathv[i]) > prec)
            prec = strlen(g->gl_pathv[i]);
    }
    for (i = 0; g->gl_pathv[i] != NULL; i += 1) {
        printf("%-*s", prec + 2, g->gl_pathv[i]);
        if (i % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n$> ");
    fflush(stdout);
    read_line_tmp_display(read_line);
}

int read_line_mouvement_tab(rd_t *read_line, int __attribute__ ((unused)) k)
{
    glob_t g;
    char *s = read_line_tmp_ptr(&(TEST)[read_line->current],
    (read_line->h->history_line)[read_line->h->history_pos]);

    if (s == NULL || glob(s, 0, NULL, &g) != 0 || g.gl_pathv == NULL) {
        free(s);
        return 0;
    }
    if (g.gl_pathc == 1) {
        read_line_filler(read_line, s, &g);
    } else if (g.gl_pathc > 1) {
        read_line_max_filler(read_line, &g);
    }
    free(s);
    globfree(&g);
    return 0;
}