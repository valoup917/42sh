/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_array_cmd
*/

#include <stdlib.h>
#include <string.h>
#include "just_shell.h"

static unsigned utils_array_cmd_tmp_count(cmd_t *cmd)
{
    unsigned n = 0;

    for (; cmd; cmd = cmd->next) {
        n++;
    }
    return n;
}

static bool utils_array_cmd_tmp_pipe(shell_t *sh, pipe_t *p, cmd_t *cmd)
{
    int i = 0;

    for (; i < p->ac; i += 1) {
        p->av[i] = utils_get_variable(sh, cmd);
        if (!p->av[i]) {
            free(p->av);
            p->av = NULL;
            return false;
        }
        cmd = cmd->next;
    }
    p->av[i] = NULL;
    p->av = utils_al_change(sh, p->av, false);
    return true;
}

bool utils_cmd_array(shell_t *sh, pipe_t *p)
{
    cmd_t *cmd;

    if (!p) {
        return false;
    }
    sh_bq_all(sh, p);
    if (shell_globling(p) == false) {
        return false;
    }
    cmd = p->pipe_cmd;
    p->ac = utils_array_cmd_tmp_count(cmd);
    if (p->ac <= 0) {
        return false;
    }
    p->av = malloc(sizeof(char *) * (p->ac + 1));
    if (!p->av) {
        return false;
    }
    return utils_array_cmd_tmp_pipe(sh, p, cmd);
}