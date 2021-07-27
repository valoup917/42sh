/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** signal_key
*/

#include <sys/ioctl.h>
#include <sys/types.h>
#include <stdbool.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "just_shell.h"
#include "read_line.h"

static int signal_key_compare(const mykey_t *key,
const char *s, compare_type_e compare)
{
    for (size_t i = 0; key[i].key_pattern != NULL; i += 1) {
        if (compare == CMP_EXACT) {
            if (my_strcmp(key[i].key_pattern, (char *) s) == 0) {
                return key[i].key_id;
            }
        } else {
            if (my_strncmp(key[i].key_pattern, s, strlen(s)) == 0) {
                return key[i].key_id;
            }
        }
    }
    return 0;
}

void signal_char_add(char *s, char c, size_t len)
{
    size_t i = 0;

    s[len - 1] = '\0';
    i = strlen(s);
    if (i <= len) {
        s[i] = c;
        s[i + 1] = '\0';
    }
}

static int signal_read_key_tmp(const mykey_t *key)
{
    char s[MAX_KEY_LEN];
    char tmp = 0;
    int result = 0;

    s[0] = '\0';
    while (signal_key_compare(key, s, CMP_CONTAINS) != 0) {
        if (read(STDIN_FILENO, &tmp, 1) != 1) {
            return (int) READ_LINE_ECS;
        }
        signal_char_add(s, tmp, MAX_KEY_LEN);
        result = signal_key_compare(key, s, CMP_EXACT);
        if (result != 0) {
            return result;
        }
    }
    return KEY_UNKNOWN;
}

int signal_read_key(const mykey_t *key)
{
    struct termios termios;
    struct termios old_termios;
    int result = 0;

    if (ioctl(STDIN_FILENO, TCGETS, &termios) == -1) {
        return KEY_ERROR;
    }
    old_termios = termios;
    termios.c_cc[VMIN] = 0;
    termios.c_cc[VTIME] = 10;
    if (ioctl(STDIN_FILENO, TCGETS, &termios) == -1) {
        return KEY_ERROR;
    }
    result = signal_read_key_tmp(key);
    if (ioctl(STDIN_FILENO, TCGETS, &old_termios) == -1) {
        return KEY_ERROR;
    }
    return result;
}