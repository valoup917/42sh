/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_six
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
#include <pwd.h>
#include "just_shell.h"

void sh_bq_all(shell_t *sh, pipe_t *p)
{
    cmd_t *cmd = p->pipe_cmd;
    cmd_t *tmp;

    for (cmd_t *tmpn; cmd; ) {
        if (cmd->command_end_idx == DELIMIT_BQUOTE) {
            tmp = cmd;
            tmpn = tmp->next;
            cmd = sh_bq_fork(sh, p, cmd);
            utils_pipe_dcmd(p, tmp);
            cmd = tmpn;
        } else {
            cmd = cmd->next;
        }
    }
}