/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** signal.char
*/

#include <sys/ioctl.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "read_line.h"
#include "his_bns.h"

bool signal_char_init(void)
{
    struct termios termios;

    if (set_termios == true) {
        return true;
    }
    if (ioctl(STDIN_FILENO, TCGETS, &termios) == -1) {
        return true;
    }
    old_termios = termios;
    set_termios = true;
    termios.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    termios.c_cc[VMIN] = 0;
    termios.c_cc[VTIME] = 1;
    if (ioctl(STDIN_FILENO, TCSETS, &termios) == -1) {
        return true;
    }
    return false;
}

bool signal_char_terminated(void)
{
    if (set_termios == false) {
        return true;
    }
    if (ioctl(STDIN_FILENO, TCSETS, &old_termios) == -1) {
        return true;
    }
    set_termios = false;
    return false;
}

int signal_char_get(const mykey_t *key)
{
    char c = 0;

    if (read(STDIN_FILENO, &c, 1) != 1) {
        return KEY_ERROR;
    }
    if (c == (char) READ_LINE_ECS) {
        return signal_read_key(key);
    }
    return (int) c;
}