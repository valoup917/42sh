/*
** EPITECH PROJECT, 2020
** Basic Function
** File description:
** Basic Function for InfinADD
*/

int my_strlen(char const *str);

int my_special_cmp_for_infadd(char *str1, char *str2)
{
    int i = 0;

    if (my_strlen(str1) - 1 > my_strlen(str2))
        return (1);
    if (my_strlen(str1) - 1 < my_strlen(str2))
        return (-1);
    for (; str2[i] && str1[i + 1] && str1[i + 1] == str2[i]; i++);
    if (str1[i + 1] > str2[i])
        return (str1[i + 1] - str2[i]);
    if (str1[i + 1] < str2[i])
        return (str1[i + 1] - str2[i]);
    return (0);
}

int get_long_chains(char *nbr1, char *nbr2)
{
    int number_one = my_strlen(nbr1);
    int number_two = my_strlen(nbr2);

    if (number_one > number_two)
        return (number_one);
    else
        return (number_two);
}

int get_the_minus(char *nbr1, char *nbr2)
{
    if ((*nbr1 == '-' && *nbr2 == '-') && (nbr1[1] == '0' && nbr2[2] == '\0'))
        return (0);
    if (*nbr1 == '-' && *nbr2 == '-')
        return (101);
    if ((*nbr1 == '-' && my_special_cmp_for_infadd(nbr1, nbr2) <= 0)
        || (*nbr2 == '-' && my_special_cmp_for_infadd(nbr2, nbr1) >= 0))
            return (102);
    if ((*nbr2 == '-' && my_special_cmp_for_infadd(nbr2, nbr1) <= 0)
        || (*nbr1 == '-' && my_special_cmp_for_infadd(nbr1, nbr2) >= 0))
            return (103);
    return (0);
}

int cond_sous_iad(char *result, int i, int buffer)
{
    if (buffer < 0)
        result[i] = result[i] + buffer + 10;
    else
        result[i] = result[i] + buffer;
    if (!(result[i] >= '0' && result[i] <= '9'))
        result[i] = '0';
    else
        return (0);
    if (!(result[i] >= '0' && result[i] <= '9'))
        result[i - 1] = '0';
    else
        return (0);
    return (0);
}
