/*
** EPITECH PROJECT, 2021
** execution
** File description:
** .
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
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

void processe(char *path, char **env, char **argv)
{
    pid_t pid = fork();
    int	status;

    if (pid == -1)
        return;
    if (pid == 0)
        execve(path, argv, env);
    else
        waitpid(pid, &status, 0);
}

static int check_one(char **tab, char *str)
{
    if (!tab) {
        my_putstr(str);
        my_putstr(": Command not found.\n");
        return 1;
    }
    return 0;
}

static int check_two(int p, char *str)
{
    if (p == 0) {
        my_putstr(str);
        my_putstr(": Command not found.\n");
        return 1;
    }
    return 0;
}

int executable(char **argv, shell_t *sh)
{
    int pr = 0;
    char *tmp = malloc(sizeof(char)*500);
    char *test = malloc(sizeof(char)*500);
    char **new = sh->sh_path;

    if (check_one(new, argv[0]))
        return 1;
    if (access(argv[0], X_OK) == 0) {
        processe(argv[0], sh->sh_array, argv);
        pr++;
    } for (int i = 0; new[i]; i++) {
        tmp = my_strct(my_strdup("/"), my_strdup(argv[0]));
        test = my_strct(my_strdup(new[i]), tmp);
        if (access(test, X_OK) == 0) {
            processe(test, sh->sh_array, argv);
            pr++;
        } if (pr > 0)
            return 0;
    } if (check_two(pr, argv[0]))
        return 1;
    return 0;
}
