/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_cd
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "builtins.h"

static void builtins_cd_environment(shell_t *sh, char *od)
{
    char *args[4];
    char directory[4096];

    sh->oldpwd = strdup(od);
    args[0] = "setenv";
    args[1] = "OLDPWD";
    args[2] = sh->oldpwd;
    args[2] = NULL;
    builtins_setenv(3, args, sh);
    if (getcwd(directory, 4096) == NULL) {
        strcpy(directory, "/");
    }
    args[1] = "PWD";
    args[2] = directory;
    builtins_setenv(3, args, sh);
}

static void check_errno_cd(shell_t *sh, char *d)
{
    if (sh->sh_wr) {
        if (errno == EACCES) {
            fprintf(stdout, NO_PERMIT, d);
        } else if (errno == ENOTDIR) {
            fprintf(stdout, NO_FOLDER, d);
        } else {
            fprintf(stdout, ERROR_NO_FILE, d);
        }
    }
}

static int builtins_cd_reset_std(char *d, shell_t *sh)
{
    char od[4096];

    if (d == NULL) {
        return EXIT_FAILURE;
    }
    if (getcwd(od, 4096) == NULL) {
        strcpy(od, "/");
    }
    if (chdir(d) == -1) {
        check_errno_cd(sh, d);
        return EXIT_FAILURE;
    }
    free(sh->oldpwd);
    builtins_cd_environment(sh, od);
    if (!sh->sh_wr) {
        utils_alias_bonus_exec(sh, "cwdcmd");
    }
    return EXIT_SUCCESS;
}

int builtins_cd(int ac, char **av, shell_t *sh)
{
    if (ac > 2) {
        if (sh->sh_wr) {
            fprintf(stdout, TOO_MANY_ARG, av[0]);
        }
        return EXIT_FAILURE;
    } else if (ac == 1) {
        return builtins_cd_reset_std(
            builtins_getenv(sh->sh_array, "HOME"), sh);
    } else {
        return (!my_strcmp(av[1], "-")) ?
        builtins_cd_reset_std(sh->oldpwd, sh) :
        builtins_cd_reset_std(av[1], sh);
    }
    return EXIT_FAILURE;
}