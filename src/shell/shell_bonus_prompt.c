/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_bonus_prompt
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
#include "parser.h"

prompt_bn_t *sh_bn_prfind(char *s)
{
    for (short i = 0; PROMPT_OPTIONS[i].rep != NULL; i += 1) {
        if (!my_strncmp(PROMPT_OPTIONS[i].rep, s,
        strlen(PROMPT_OPTIONS[i].rep)))
            if (PROMPT_OPTIONS[i].func != NULL)
                return (prompt_bn_t *) (&PROMPT_OPTIONS[i]);
    }
    return NULL;
}

void sh_bn_wr(shell_t *sh, char *s)
{
    prompt_bn_t *pp;

    for (unsigned i = 0; s[i]; i += 1) {
        pp = sh_bn_prfind(&s[i]);
        if (pp) {
            (pp->func)(sh);
            i += strlen(pp->rep) - 1;
        } else {
            printf("%c", s[i]);
        }
    }
}

void sh_pp_nb(shell_t *sh)
{
    lcl_t *lcl;
    char *pp = NULL;

    utils_alias_bonus_exec(sh, "precmd");
    if (isatty(STDIN_FILENO)) {
        pp = "?> ";
        lcl = utils_lcl_fnode("MY_PROMPT", sh->lcl);
        if (lcl) {
            pp = lcl->lcl_value;
        }
        sh_bn_wr(sh, pp);
        fflush(stdout);
    }
}

bool sh_open_folder(shell_t *sh)
{
    char *s = NULL;
    int fd = open(".42sh", O_RDONLY);

    if (fd == -1) {
        return false;
    }
    while ((s = my_get_next_line(fd)) != NULL) {
        sh_command_control(sh, s);
    }
    close(fd);
    return true;
}