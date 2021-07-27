/*
** EPITECH PROJECT, 2020
** my_usage
** File description:
** usage do op advanced
*/

#include <unistd.h>

long my_usage(int a, int b)
{
    (void)a;
    (void)b;
    write(2, "error: only [ + - / * % ] are supported\n", 40);
    return (84);
}
