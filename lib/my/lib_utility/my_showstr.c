/*
** EPITECH PROJECT, 2020
** My_showstr
** File description:
** Print non printable char
*/

#include <unistd.h>

void my_putchar(char c);

void my_convert_to_hexa(char hex_number)
{
    char *hex_base = "0123456789abcdef";

    if (hex_number < 16)
        my_putchar('0');
    else
        my_putchar(hex_base[hex_number / 16]);
    my_putchar(hex_base[hex_number % 16]);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 32 && str[i] <= 126)) {
            my_putchar('\\');
            my_convert_to_hexa(str[i]);
        }
        else
            my_putchar(str[i]);
    }
    return (0);
}
