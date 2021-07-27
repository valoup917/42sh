/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins
*/

#ifndef BUILTINS_H_
#define BUILTINS_H_

#include "just_shell.h"
#include "prototype.h"

typedef struct {
    char *name;
    int (*func) (int, char **, shell_t *);
} builtins_t;

static const builtins_t BUILTINS_ARRAY[] = {
    {"cd", builtins_cd},
    {"exit", builtins_exit},
    {"env", builtins_env},
    {"setenv", builtins_setenv},
    {"unsetenv", builtins_unsetenv},
    {"history", builtins_history},
    {"builtins", builtins_builtins},
    {"alias", builtins_alias},
    {"where", builtins_where},
    {"which", builtins_which},
    {"fg", builtins_fg},
    {"jobs", builtins_jobs},
    {"set", builtins_set},
    {"repeat", builtins_repeat},
    {"foreach", builtins_foreach},
    {"help", builtins_help},
    {"end", builtins_end},
    {NULL, NULL},
};

#endif /* !BUILTINS_H_ */
