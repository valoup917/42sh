/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_part_one
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <glob.h>
#include "just_shell.h"

int shell_signal_status(int st)
{
    if (WIFSIGNALED(st)) {
        signal_display_error(st);
        return (SCHAR_MAX + 1) + WTERMSIG(st);
    }
    if (WIFEXITED(st)) {
        return WEXITSTATUS(st);
    }
    if (WIFSTOPPED(st)) {
        return WSTOPSIG(st);
    }
    return EXIT_SUCCESS;
}

void shell_replace_groups(pid_t pid)
{
    if (isatty(STDIN_FILENO)) {
        tcsetpgrp(STDERR_FILENO, pid);
        tcsetpgrp(STDIN_FILENO, pid);
        tcsetpgrp(STDOUT_FILENO, pid);
    }
}

void shell_status_close(shell_t *sh, unsigned char status)
{
    if (sh->oldpwd) {
        free(sh->oldpwd);
    }
    free_sh_cmd(sh);
    utils_lcl_dlist(sh->lcl);
    utils_al_del_list(sh->alias);
    utils_jb_dlist(sh, sh->jobs);
    utils_hs_dlist(sh->history);
    utils_free_array(sh->sh_path);
    utils_free_array(sh->sh_array);
    read_line_free();
    exit(status);
}

void shell_init_prompt_error(void)
{
    if (isatty(STDIN_FILENO)) {
        printf("? ");
        fflush(stdout);
    }
}