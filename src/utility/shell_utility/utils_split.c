/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** utils_split
*/

#include <stdlib.h>
#include <string.h>

static char **split_tmp(char **array, char *s, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (; s[i]; i += 1) {
        if ((c != ' ' && s[i] == c) || (c == ' ' && (s[i] == ' '))
        || s[i] == '\t') {
            array[j++] = strndup(&s[k], i - k);
            k = i + 1;
        }
    }
    array[j++] = strndup(&s[k], i - k);
    array[j] = NULL;
    return array;
}

static unsigned tmp_char_size(char *s, char c)
{
    unsigned res = 0;

    for (; *s; s += 1) {
        if (*s == c) {
            res += 1;
        }
    }
    return res;
}

char **my_str_to_word_array_gl(char *s, char c)
{
    char **array = NULL;
    unsigned i = 0;

    if (!s) {
        return NULL;
    }
    i = tmp_char_size(s, c);
    if (c == ' ') {
        i += tmp_char_size(s, '\t');
    }
    array = malloc(sizeof(char *) * (i + 2));
    if (!array) {
        return NULL;
    }
    return split_tmp(array, s, c);
}