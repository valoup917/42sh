/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_env
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "just_shell.h"
#include "builtins.h"

int builtins_env(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh)
{
    if (!sh->sh_wr) {
        return 0;
    }
    if (sh->sh_array != NULL) {
        for (int i = 0; sh->sh_array[i]; i += 1) {
            printf("%s\n", sh->sh_array[i]);
        }
    }
    return 0;
}

int builtins_execution(shell_t *sh, pipe_t *p)
{
    short i = check_builtins(p->av[0]);

    if (i != -1) {
        sh->pipe = p;
        if (BUILTINS_ARRAY[i].func != NULL) {
            return (BUILTINS_ARRAY[i].func)(p->ac, p->av, sh);
        }
    }
    return 1;
}

static int builtins_exit_errors(shell_t *sh, char *s, char **av)
{
    int i = 0;

    if (s[i] && s[i] == '-')
        i++;
    for (; s[i]; i += 1) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            if (sh->sh_wr) {
                fprintf(stdout, "%s: Expression Syntax.\n", av[0]);
            }
            return 1;
        }
    }
    if (i == 1 && s[0] == '-') {
        if (sh->sh_wr) {
            fprintf(stdout, "%s: Badly formed number.\n", av[0]);
        }
        return 1;
    }
    return 0;
}

int builtins_exit(int ac, char **av, shell_t *sh)
{
    unsigned char check = 0;

    if (ac > 2) {
        if (sh->sh_wr) {
            fprintf(stdout, "%s: Badly formed number.\n", av[0]);
        }
        return 1;
    }
    if (ac > 1) {
        if (builtins_exit_errors(sh, av[1], av) == 1)
            return 1;
        check = atoi(av[1]);
    }
    if (sh->pipe->next == NULL) {
        sh->actual_exit = true;
    } else if (sh->pipe->prev != NULL) {
        shell_status_close(sh, check);
    }
    return check;
}

int builtins_history(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh)
{
    previous_t *h;
    struct tm *nt;

    if (!sh->sh_wr) {
        return 0;
    }
    for (h = utils_hs_back(sh->history); h; h = h->next) {
        printf("%u\t", h->id);
        nt = localtime(&h->prev_date);
        if (nt != NULL) {
            printf("%02d:%02d\t", nt->tm_hour, nt->tm_min);
        }
        printf("%s\n", h->str);
    }
    return 0;
}