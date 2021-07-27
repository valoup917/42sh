/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_linked_list
*/

#include <stdlib.h>
#include "just_shell.h"

void utils_linked_list_dlist(list_t *ls)
{
    for (list_t *tmp; ls; free(tmp)) {
        tmp = ls;
        ls = ls->next;
        if (tmp->list_cmd) {
            utils_cmd_dlist(tmp->list_cmd);
        }
        if (tmp->p) {
            utils_pipe_dlist(tmp->p);
        }
    }
}

void utils_linked_list_dnode(shell_t *sh, list_t *ls)
{
    if (ls->prev) {
        ls->prev->next = ls->next;
    } else {
        sh->list = ls->next;
    }
    if (ls->next) {
        ls->next->prev = ls->prev;
    }
    if (ls->list_cmd) {
        utils_cmd_dlist(ls->list_cmd);
    }
    free(ls);
}

list_t *utils_linked_list_ar(list_t *ls, cmd_t *cmd, short ts)
{
    list_t *res = malloc(sizeof(*res));

    if (!res) {
        return NULL;
    }
    res->prev = ls;
    res->next = NULL;
    res->list_cmd = cmd;
    res->list_sep = ts;
    res->list_threat = true;
    res->p = NULL;
    res->list_bg = false;
    if (ls) {
        if (ls->next) {
            res->next = ls->next;
            ls->next->prev = res;
        }
        ls->next = res;
    }
    return res;
}

list_t *utils_linked_list_move_back(list_t *ls)
{
    for (; ls && ls->prev; ls = ls->prev);
    return ls;
}