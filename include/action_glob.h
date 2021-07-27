/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** action_glob
*/

#ifndef ACTION_GLOB_H_
#define ACTION_GLOB_H_

#include "read_line.h"

static action_t ACTION_GLOBAL[] = {
    {read_line_mouvements_left, KEY_LEFT},
    {read_line_mouvements_right, KEY_RIGHT},
    {read_line_mouvements_up, KEY_UP},
    {read_line_mouvement_down, KEY_DOWN},
    {read_line_mouvements_controll, KEY_CONTROLL},
    {read_line_mouvement_remove, KEY_DEL},
    {read_line_mouvement_tab, KEY_TAB},
    {read_line_mouvements_back, KEY_BACK},
    {NULL, KEY_UNKNOWN}
};

#endif /* !ACTION_GLOB_H_ */
