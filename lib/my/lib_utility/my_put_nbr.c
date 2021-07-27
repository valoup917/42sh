/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Displays the number given as a parameter
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    unsigned int n;

    if (nb < 0) {
        my_putchar('-');
        n = nb * (-1);
    } else {
        n = nb;
    }
    if (n > 9) {
        my_put_nbr(n / 10);
        n = n % 10;
    }
    my_putchar(n + '0');
    return (0);
}
