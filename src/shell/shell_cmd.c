/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** shell_cmd
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
#include "read_line.h"
#include "parser.h"

void sh_command_control(shell_t *sh, char *s)
{
    if (s) {
        free_sh_cmd(sh);
        if (sh_parser_global(sh, s) == false) {
            sh->sh_rt = 1;
        }
        free(s);
        sh_linked_thread(sh);
        free_sh_cmd(sh);
        if (sh->actual_exit == true) {
            printf("exit\n");
            shell_status_close(sh, sh->sh_rt);
        }
    }
}

bool sh_command_rcontrol(shell_t *sh, const char *sl)
{
    char *s = NULL;

    utils_alias_bonus_exec(sh, "postcmd");
    s = strdup(sl);
    if (!s)
        return false;
    if (strlen(s) > 0)
        sh->history = utils_hs_ar(sh->history, strdup(sl));
    sh_command_control(sh, s);
    return true;
}

bool sg_cmd_get(shell_t *sh)
{
    const char *s = NULL;

    sh_pp_nb(sh);
    while (1) {
        s = read_line_line(STDOUT_FILENO, KEY_ARRAY);
        if (s) {
            if (sh_command_rcontrol(sh, s) == false) {
                read_line_free();
                return false;
            }
        } else if (utils_lcl_fnode("ignoreof", sh->lcl) != NULL) {
            printf(MESS_CTRLD, "42sh");
        } else {
            printf("exit\n");
            read_line_free();
            return true;
        }
        sh_pp_nb(sh);
    }
    read_line_free();
    return true;
}

bool sg_cmd_get_mou_mou(shell_t *sh)
{
    char *s = NULL;

    sh_pp_nb(sh);
    while ((s = my_get_next_line(STDIN_FILENO)) != NULL) {
        utils_alias_bonus_exec(sh, "postcmd");
        if (strlen(s) > 0)
            sh->history = utils_hs_ar(sh->history, strdup(s));
        sh_command_control(sh, s);
        sh_pp_nb(sh);
    }
    return true;
}