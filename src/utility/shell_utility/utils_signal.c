/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_signal
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include "parser.h"

static void temp_utils_signal(int i, int status)
{
    fprintf(stderr, "%s", SIGNAL_ARRAY[i].description);
    if (WCOREDUMP(status)) {
        fprintf(stderr, " (core dumped)");
    }
    fprintf(stderr, "\n");
}

void signal_display_error(int status)
{
    int i = 0;

    if (WIFSIGNALED(status)) {
        for (; SIGNAL_ARRAY[i].description != NULL; i += 1) {
            if (SIGNAL_ARRAY[i].code == WTERMSIG(status)) {
                temp_utils_signal(i, status);
                return;
            }
        }
    }
}