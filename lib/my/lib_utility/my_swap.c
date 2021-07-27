/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Swap two value
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
