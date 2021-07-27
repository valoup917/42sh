/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** builtins_where
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aliases.h"
#include "builtins.h"

static bool search_alias(char *av, alias_t *alias)
{
    for (alias_t *count = alias; count; count = count->next) {
        if (!compare_str_2d_array(av, count->alias_find)) {
            printf("%s is aliased to ", av);
            print_2d_array(count->alias_redi);
            return true;
        }
    }
    return false;
}

static int get_good_path(char *s, shell_t *sh)
{
    char *buf = NULL;
    int j = 0;

    if (!s)
        return 1;
    for (int i = 0, size = strlen(s); sh->sh_path[i]; i += 1) {
        size = strlen(s) + strlen(sh->sh_path[i]) + 2;
        if (s[i] == '/') {
            fprintf(stderr, "where: / in command makes no sense\n");
            return 2;
        } if ((buf = realloc(buf, sizeof(char) * size)) == NULL)
            return 1;
        memset(buf, 0, size);
        strcat(buf, sh->sh_path[i]);
        strcat(buf, "/");
        strcat(buf, s);
        j += (shell_tmp_access(buf)) ? printf("%s\n", buf) : 0;
    }
    if (buf)
        free(buf);
    return (j) ? 0 : 1;
}

static int get_good_path_part_two(char **av, shell_t *sh)
{
    bool check = false;
    int tmp = 0;

    if (!sh->sh_wr)
        return 0;
    if (!sh->sh_path)
        return 1;
    for (int i = 1, alias = 0, get = 0; av[i]; i += 1) {
        check = search_alias(av[i], sh->alias);
        alias = check;
        if (check_builtins(av[i]) != -1) {
            printf(IS_BUILTIN_WITH, av[i]);
            check = 1;
        } if ((get = get_good_path(av[i], sh)) == 2) {
            tmp = 1;
        } else if (get == 0) {
            check = 1;
        } if (alias != check && get == 1)
            check = 0;
    }
    return (tmp == 1) ? 1 : (check) ? 0 : 1;
}

int builtins_where(int __attribute__ ((unused)) ac, char **av, shell_t *sh)
{
    if (ac < 2) {
        if (sh->sh_wr) {
            fprintf(stdout, TOO_FEW_ARG, av[0]);
        }
        return 1;
    }
    return get_good_path_part_two(av, sh);
}