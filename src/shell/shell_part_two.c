/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_two
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include "just_shell.h"

void shell_prdi_error_open(shell_t *sh, pipe_t *p)
{
    int fd[2];

    if (p->next) {
        if (pipe(fd) == -1) {
            fprintf(stderr, ERROR_FUNCTION, "pipe");
            shell_status_close(sh, EXIT_FAILURE);
        }
        p->next->fd[PIPE_FD_IN] = fd[0];
        p->fd[PIPE_FD_OUT] = fd[1];
    }
}

static bool shell_aredi_dp_tmp(shell_t *sh, pipe_t *p)
{
    int fd[2];

    fd[PIPE_FD_IN] = 0;
    fd[PIPE_FD_OUT] = 0;
    if (shell_redi_status(sh, p, fd) == false) {
        return false;
    }
    if (fd[PIPE_FD_IN] > 0) {
        if (p->fd[PIPE_FD_IN] != -1) {
            close(p->fd[PIPE_FD_IN]);
        }
        p->fd[PIPE_FD_IN] = fd[PIPE_FD_IN];
    }
    if (fd[PIPE_FD_OUT] > 0) {
        if (p->fd[PIPE_FD_OUT] != -1) {
            close(p->fd[PIPE_FD_OUT]);
        }
        p->fd[PIPE_FD_OUT] = fd[PIPE_FD_OUT];
    }
    return true;
}

bool shell_aredi_dp(shell_t *sh, pipe_t *p)
{
    if (shell_aredi_dp_tmp(sh, p) == false) {
        return false;
    }
    if ((sh->fd[PIPE_FD_IN] != STDIN_FILENO && !p->prev &&
    dup2(sh->fd[PIPE_FD_IN], 0) == -1) || (p->fd[PIPE_FD_IN] != -1 &&
    dup2(p->fd[PIPE_FD_IN], 0) == -1)) {
        fprintf(stderr, ERROR_FUNCTION, "dup2");
        shell_status_close(sh, EXIT_FAILURE);
    }
    if ((sh->fd[PIPE_FD_OUT] != STDOUT_FILENO && !p->next &&
    dup2(sh->fd[PIPE_FD_OUT], 1) == -1) || (p->fd[PIPE_FD_OUT] != -1 &&
    dup2(p->fd[PIPE_FD_OUT], 1) == -1)) {
        fprintf(stderr, ERROR_FUNCTION, "dup2");
        shell_status_close(sh, EXIT_FAILURE);
    }
    shell_prdi_error(p);
    if (p->next) {
        close(p->next->fd[PIPE_FD_IN]);
    }
    return true;
}

bool shell_tmp_access(char *s)
{
    if (access(s, X_OK) == 0) {
        return true;
    } else if (errno == ENOTDIR) {
        fprintf(stderr, ERROR_NOT_FOLDER, s);
    }
    return false;
}

char *shell_tmpt_fprg(shell_t *sh, char *s)
{
    int size = strlen(s);
    char *res = NULL;

    for (int i = 0; sh->sh_path[i]; i += 1) {
        size = strlen(s) + strlen(sh->sh_path[i]) + 2;
        res = realloc(res, sizeof(char) * size);
        memset(res, '\0', size);
        res = strcat(res, sh->sh_path[i]);
        if (!res)
            return NULL;
        res = strcat(res, "/");
        if (!res)
            return NULL;
        res = strcat(res, s);
        if (!res)
            return NULL;
        if (shell_tmp_access(res))
            return res;
    } if (res)
        free(res);
    return NULL;
}