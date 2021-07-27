/*
** EPITECH PROJECT, 2021
** part 4
** File description:
** .
*/

#include <string.h>
#include <stdlib.h>
#include "builtins.h"

char **end_p2(char **tmp, char *variable, char **test, int a)
{
    for (int q = 0; tmp[q]; q++) {
        if (!strcmp(tmp[q], variable)) {
            tmp[q] = malloc(sizeof(char) * strlen(test[a]) + 10);
            strcpy(tmp[q], test[a]);
        }
    }
    return tmp;
}