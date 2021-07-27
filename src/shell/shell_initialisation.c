/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_initialisation
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

void shell_initialisation_pth(shell_t *sh)
{
    char tmp[4096];
    char *s = builtins_getenv(sh->sh_array, "PATH");

    if (!s) {
        memset(tmp, '\0', 4096);
        confstr(_CS_PATH, tmp, 4096);
        sh->sh_path = my_str_to_word_array_gl(tmp, ':');
    } else {
        sh->sh_path = my_str_to_word_array_gl(s, ':');
    }
}

static void init_tmp(shell_t *sh)
{
    sh->commands = NULL;
    sh->list = NULL;
    sh->lcl = NULL;
    sh->sh_rt = 0;
    sh->fd[PIPE_FD_IN] = STDIN_FILENO;
    sh->fd[PIPE_FD_OUT] = STDOUT_FILENO;
    sh->sh_wr = false;
    sh->alias = NULL;
    sh->jobs = NULL;
    sh->pipe = NULL;
    sh->actual_exit = false;
    sh->history = NULL;
}

bool shell_initialisation(shell_t *sh, int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, char **arr)
{
    sh->sh_array = utils_array_copy(arr);
    if (!sh->sh_array) {
        return false;
    }
    init_tmp(sh);
    shell_initialisation_pth(sh);
    sh->pid.pid = getpid();
    sh->pid.pgid = getpgid(sh->pid.pid);
    if (sh->pid.pgid == -1)
        return false;
    sh_init_ushell_pass(sh);
    sh_init_ushell(sh);
    return true;
}