/*
** EPITECH PROJECT, 2021
** foreach
** File description:
** .
*/

#include <stdio.h>
#include <string.h>
#include <builtins.h>

static char *my_strct(char *dest, char *src)
{
    int i = my_strlen(dest);
    int j = 0;
    int x = 0;
    int i2 = my_strlen(src);
    char *new = malloc(sizeof(char)*(i + i2 + 1));

    for (; x < (i + i2); x++) {
        if (x < i)
            new[x] = dest[x];
        else {
            new[x] = src[j];
            j++;
        }
    }
    new[x] = '\0';
    return new;
}

int count_obj(char **argv)
{
    int i = 0;
    char **tmp = NULL;

    if (!argv || !argv[0] || !argv[1])
        return 0;
    tmp = my_stwa(argv[2]);
    for (int a = 0; tmp[a]; a++) {
        if (strcmp("\0", tmp[i])) {
            i++;
        }
    }
    return (i);
}

int end_frch(char *line, char **cmds, shell_t *sh, char **argv)
{
    char *variable = malloc(sizeof(char) * 100);
    char **test = NULL;

    variable = my_strct(strdup("$"), argv[1]);
    test = my_stwa(argv[2]);
    if (strcmp("end", line))
        return 0;
    if (!cmds || cmds[0] == NULL)
        return 1;
    for (int a = 0; a != count_obj(argv); a++) {
        for (int i = 0; cmds[i];i++) {
            char **tmp = my_stwa(cmds[i]);
            tmp = end_p2(tmp, variable, test, a);
            executable(tmp, sh);
        }
    }
    free(variable);
    return 1;
}

void get_foreach(shell_t *sh, char **argv)
{
    char *line = NULL;
    int a = 0;
    char **frch_commands = malloc(sizeof(char *) * 100);
    frch_commands[0] = NULL;

    for (int i = 0; (line = my_get_next_line(STDIN_FILENO)) != NULL; i++) {
        if (!end_frch(line, frch_commands, sh, argv)) {
            frch_commands[a] = malloc(sizeof(char) * (strlen(line) + 100));
            strcpy(frch_commands[a], line);
            a++;
            frch_commands[a] = NULL;
        }
        else
            return;
    }
}

int builtins_foreach(int __attribute__ ((unused)) ac, char **argv, shell_t *sh)
{
    if (sh->sh_wr && check_errors_foreach(ac, argv, sh))
        return 1;
    else if (sh->sh_wr)
        get_foreach(sh, argv);
    return 0;
}