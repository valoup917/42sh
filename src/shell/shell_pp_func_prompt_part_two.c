/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_pp_func_prompt_part_two
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

void sh_pp_user(shell_t __attribute__ ((unused)) *sh)
{
    struct passwd *pass = getpwuid(geteuid());

    if (!pass) {
        return;
    }
    printf("%s", pass->pw_name);
}

void sh_pp_get_time(shell_t __attribute__ ((unused)) *sh)
{
    struct tm *ac;
    time_t n = 0;

    time(&n);
    ac = localtime(&n);
    if (ac != NULL) {
        printf("%02d:%02d", ac->tm_hour, ac->tm_min);
    }
}

void sh_pp_get_ee(shell_t __attribute__ ((unused)) *sh)
{
    printf("\e");
}