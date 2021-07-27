/*
** EPITECH PROJECT, 2021
** my_memcpy
** File description:
** my own memcpy
*/

#include "macro_and_define.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned int i = 0;
    unsigned char *result = (unsigned char *) dest;
    unsigned const char *s = (unsigned char *) src;

    if (dest == NULL && src == NULL)
        return NULL;
    for (; i < n; i++)
        *((char *) result + i) = *((char *) s + i);
    return result;
}