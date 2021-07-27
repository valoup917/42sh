/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** main.c
*/

#include <sys/wait.h>
#include <unistd.h>
#include "just_shell.h"

void refresh_wait(void)
{
    int st = 0;

    for (int i = 0; i < 100; i += 1) {
        wait(&st);
    }
}

int main(int ac, char **av, char **env)
{
    shell_t sh;

    if (ac != 1) {
        return 84;
    }
    refresh_wait();
    get_sh_sig(true);
    if (shell_initialisation(&sh, ac, av, env) == false) {
        return 84;
    }
    sh_open_folder(&sh);
    if (ac == 1) {
        (isatty(STDIN_FILENO)) ?
        sg_cmd_get(&sh) :
        sg_cmd_get_mou_mou(&sh);
    }
    shell_status_close(&sh, sh.sh_rt);
    return 0;
}