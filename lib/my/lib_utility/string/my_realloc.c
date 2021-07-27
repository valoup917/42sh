/*
** EPITECH PROJECT, 2021
** my_realloc
** File description:
** my own realloc
*/

#include "macro_and_define.h"

void *my_realloc(void *ptr, size_t size)
{
    char *dest;

    if (!ptr)
        dest = malloc(size);
    if (!size && ptr) {
        free(ptr);
        return ptr;
    }
    dest = malloc(size);
    if (!dest)
        return NULL;
    my_memcpy(dest, ptr, size);
    free(ptr);
    ptr = dest;
    return ptr;
}