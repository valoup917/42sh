/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_path
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pwd.h>
#include "just_shell.h"

char *utils_path_get_cuser(void)
{
    struct passwd *p = getpwuid(geteuid());

    if (!p) {
        return NULL;
    }
    return p->pw_dir;
}

char *utils_path_get_cname(cmd_t *cmd)
{
    struct passwd *p;
    char *s = strdup(&cmd->commands[1]);
    int i = 0;

    if (!s) {
        return NULL;
    }
    for (; s[i] && s[i] != '/'; i += 1);
    s[i] = '\0';
    p = getpwnam(s);
    if (!p) {
        fprintf(stderr, "Unknown user: %s.\n", s);
        free(s);
        return NULL;
    }
    free(s);
    return p->pw_dir;
}

char *utils_path_chome(cmd_t *cmd, char *s)
{
    char *n = NULL;
    size_t j = 0;
    size_t i = 0;

    for (; cmd->commands[i] && cmd->commands[i] != '/'; i += 1);
    j = strlen(&cmd->commands[i]) + strlen(s) + 1;
    n = malloc(sizeof(char) * j);
    if (!n) {
        return NULL;
    }
    n = memset(n, '\0', j);
    strcat(n, s);
    strcat(n, &cmd->commands[i]);
    free(cmd->commands);
    cmd->commands = n;
    return cmd->commands;
}

char *util_get_environ_path(cmd_t *cmd)
{
    char *s = NULL;

    if (!my_strcmp(cmd->commands, "~") || !my_strncmp(cmd->commands, "~/", 2)) {
        s = utils_path_get_cuser();
        if (!s) {
            return NULL;
        }
    } else {
        s = utils_path_get_cname(cmd);
        if (!s) {
            return NULL;
        }
    }
    return utils_path_chome(cmd, s);
}