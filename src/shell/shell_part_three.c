/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_three
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <pwd.h>
#include "just_shell.h"

char *shell_rd_dir(char *s)
{
    char *res = malloc(sizeof(char) * (strlen(s) + 3));

    if (!res) {
        return NULL;
    }
    memset(res, '\0', strlen(s) + 3);
    strcat(res, "./");
    strcat(res, s);
    if (shell_tmp_access(res)) {
        return res;
    }
    free(res);
    return NULL;
}

char *sh_path_env(shell_t *sh, char *s)
{
    char *res = NULL;

    if (!s)
        return NULL;
    if (my_strncmp(s, "./", 2) && my_strncmp(s, "/", 1)) {
        if (strstr(s, "/") != NULL) {
            return shell_rd_dir(s);
        } else {
            if (!sh->sh_path)
                return NULL;
            res = shell_tmpt_fprg(sh, s);
            if (res)
                return res;
        }
    } else {
        if (shell_tmp_access(s))
            return strdup(s);
    }
    return NULL;
}

int sh_get_par(shell_t *sh, pipe_t *p)
{
    p->pipe_pid = fork();
    if (p->pipe_pid == -1) {
        fprintf(stderr, ERROR_FUNCTION, "fork");
        shell_status_close(sh, EXIT_FAILURE);
    } else if (p->pipe_pid == 0) {
        if (p->fd[PIPE_FD_IN] != -1) {
            sh->fd[PIPE_FD_IN] = p->fd[PIPE_FD_IN];
        }
        if (p->fd[PIPE_FD_OUT] != -1) {
            sh->fd[PIPE_FD_OUT] = p->fd[PIPE_FD_OUT];
        }
        sh_command_control(sh, strdup(p->pipe_cmd->commands));
        shell_status_close(sh, sh->sh_rt);
    }
    return EXIT_SUCCESS;
}

bool sh_init_ushell(shell_t *sh)
{
    char *n = NULL;
    char *args[4];
    struct passwd *pass = getpwuid(geteuid());

    if (!pass)
        return false;
    n = builtins_getenv(sh->sh_array, "USER");
    if (!n) {
        args[0] = "setenv";
        args[1] = "USER";
        args[2] = pass->pw_name;
        args[3] = NULL;
        builtins_setenv(3, args, sh);
    }
    return true;
}

void sh_init_ushell_pass(shell_t *sh)
{
    char od[4096];
    char *n = NULL;
    char *args[4];

    if (getcwd(od, 4096) == NULL)
        strcpy(od, "/");
    sh->oldpwd = strdup(od);
    n = builtins_getenv(sh->sh_array, "PWD");
    if (!n) {
        args[0] = "setenv";
        args[1] = "PWD";
        args[2] = sh->oldpwd;
        args[3] = NULL;
        builtins_setenv(3, args, sh);
    }
}