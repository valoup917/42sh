/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_globling
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glob.h>
#include "just_shell.h"

static bool sh_shell_globling_check(char *s)
{
    if (!s) {
        return false;
    }
    for (; *s; s += 1) {
        if (*s == '*') {
            return true;
        }
    }
    return false;
}

static cmd_t *sh_shell_globling_find(cmd_t *f, cmd_t *cmd, bool *check)
{
    glob_t g;

    if (glob(cmd->commands, 0, NULL, &g) != 0) {
        *check = false;
        fprintf(stderr, ERROR_NO_MATCH, f->commands);
        return cmd;
    }
    if (!g.gl_pathv) {
        return cmd;
    }
    for (int i = 0; g.gl_pathv[i]; i += 1) {
        cmd = utils_cmd_radd(cmd, strdup(g.gl_pathv[i]), DELIMIT_WITHOUT);
    }
    globfree(&g);
    return cmd;
}

bool shell_globling(pipe_t *p)
{
    cmd_t *cmd = p->pipe_cmd;
    cmd_t *tmp;
    cmd_t *tmpn;

    for (bool check; cmd; ) {
        if (cmd->command_end_idx == DELIMIT_WITHOUT &&
        sh_shell_globling_check(cmd->commands)) {
            check = true;
            tmp = cmd;
            tmpn = tmp->next;
            cmd = sh_shell_globling_find(p->pipe_cmd, cmd, &check);
            if (check == false) {
                return false;
            }
            utils_pipe_dcmd(p, tmp);
            cmd = tmpn;
        } else {
            cmd = cmd->next;
        }
    }
    return true;
}