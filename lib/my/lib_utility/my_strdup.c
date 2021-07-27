/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Allocates memory and copies the string given
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return (NULL);
    for (i = 0; src[i]; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
