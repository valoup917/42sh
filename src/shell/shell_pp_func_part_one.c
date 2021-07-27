/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_pp_func_part_one
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include "just_shell.h"

void sh_pp_dir(shell_t __attribute__ ((unused)) *sh)
{
    char directory[4096];

    if (getcwd(directory, 4096) == NULL) {
        strcpy(directory, "/");
    }
    printf("%s", directory);
}

void sh_pp_count_line(shell_t __attribute__ ((unused)) *sh)
{
    (sh->history) ?
    printf("%u", sh->history->id + 1) :
    printf("1");
}

void sh_pp_rt_val(shell_t __attribute__ ((unused)) *sh)
{
    if (sh->sh_rt == 0) {
        printf("\033[32m%hd\033[0m", sh->sh_rt);
    } else {
        printf("\033[31m%hd\033[0m", sh->sh_rt);
    }
}

void sh_pp_ver(shell_t __attribute__ ((unused)) *sh)
{
    printf("42sh");
}

void sh_pp_eof(shell_t __attribute__ ((unused)) *sh)
{
    printf("\n");
}