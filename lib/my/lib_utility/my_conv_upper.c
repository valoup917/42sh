/*
** EPITECH PROJECT, 2020
** Conv to upper
** File description:
** Conv to UPPER
*/

void conv_to_upper(char *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;
}
