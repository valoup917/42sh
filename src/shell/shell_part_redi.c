/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_redi
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "just_shell.h"

char *shell_tmp_astring(char *ct, char *s)
{
    int j = strlen(ct) + strlen(s) + 2;

    ct = realloc(ct, sizeof(char) * j);
    if (!ct) {
        free(s);
        return NULL;
    }
    ct = strcat(ct, s);
    ct = strcat(ct, "\n");
    return ct;
}

char *shell_rgetline(char *s)
{
    char *ct = malloc(sizeof(char));
    char *str = NULL;

    if (!ct)
        return NULL;
    ct[0] = '\0';
    shell_init_prompt_error();
    while ((str = my_get_next_line(STDIN_FILENO)) != NULL &&
    my_strcmp(s, str)) {
        ct = shell_tmp_astring(ct, str);
        if (!ct)
            return NULL;
        free(str);
        str = NULL;
        shell_init_prompt_error();
    }
    if (str)
        free(str);
    return ct;
}

int shell_rtleft(shell_t *sh, pipe_t *p)
{
    int fd[2];
    char *ct = shell_rgetline(p->redirection[REDIRECT_TLEFT]);

    if (!ct) {
        return -1;
    } if (pipe(fd) == -1) {
        fprintf(stderr, ERROR_FUNCTION, "pipe");
        shell_status_close(sh, EXIT_FAILURE);
    } if (write(fd[1], ct, strlen(ct)) == -1) {
        close(fd[1]);
        fprintf(stderr, ERROR_FUNCTION, "write");
        shell_status_close(sh, EXIT_FAILURE);
    }
    close(fd[1]);
    if (dup2(fd[0], 0) == -1) {
        fprintf(stderr, ERROR_FUNCTION, "dup2");
        shell_status_close(sh, EXIT_FAILURE);
    } if (ct) {
        free(ct);
    }
    return fd[0];
}

bool shell_redi_status(shell_t *sh, pipe_t *p, int *fd)
{
    int mode = 0;

    if (p->redirection[REDIRECT_RIGHT]) {
        mode = O_RDONLY | O_CREAT | O_RDWR | O_TRUNC;
        fd[PIPE_FD_OUT] = open(p->redirection[REDIRECT_RIGHT], mode, 0644);
    }
    if (p->redirection[REDIRECT_TRIGHT]) {
        mode = O_RDONLY | O_CREAT | O_RDWR | O_APPEND;
        fd[PIPE_FD_OUT] = open(p->redirection[REDIRECT_TRIGHT], mode, 0644);
    }
    if (p->redirection[REDIRECT_LEFT]) {
        mode = O_RDONLY;
        fd[PIPE_FD_IN] = open(p->redirection[REDIRECT_LEFT], mode);
        if (fd[PIPE_FD_IN] == -1) {
            fprintf(stderr, ERROR_NO_FILE, p->redirection[REDIRECT_LEFT]);
            return false;
        }
    }
    if (p->redirection[REDIRECT_TLEFT])
        fd[PIPE_FD_IN] = shell_rtleft(sh, p);
    return true;
}

void shell_prdi_error(pipe_t *p)
{
    if (p->fd[PIPE_FD_OUT] > STDOUT_FILENO) {
        close(p->fd[PIPE_FD_OUT]);
    }
    p->fd[PIPE_FD_OUT] = STDOUT_FILENO;
    if (p->fd[PIPE_FD_IN] > STDIN_FILENO) {
        close(p->fd[PIPE_FD_IN]);
    }
    p->fd[PIPE_FD_IN] = STDIN_FILENO;
}