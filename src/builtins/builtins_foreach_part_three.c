/*
** EPITECH PROJECT, 2021
** foreach part
** File description:
** .
*/

#include <builtins.h>

int nbr_letters(char *str, int rank)
{
    int i = rank;
    int a = 0;
    for (;(str[i] >= '!' && str[i] <= '9') || (str[i] >= 'a' &&
    str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ';'
    || str[i] == '>' || str[i] == '<' || str[i] == '|' || str[i] == '_'
    || str[i] == '/' || str[i] == '.'); i++) {
        a++;
    }
    return a;
}

int nb_words(char *str)
{
    int x = 0;
    int i = 0;
    while (str[i + 1] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            x++;
        }
        i++;
        while (str[i + 1] == ' ') {
            i++;
        }
    }
    x++;
    return x;
}

int is_good(char c)
{
    if ((c >= '!' && c <= '9') ||
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c == ';' || c == '>' || c == '<' || c == '|'
        || c == '_' || c == '/' || c == '.'))
        return (1);
    else
        return (0);
}

char **my_stwa(char *str)
{
    char **new = malloc(sizeof(char *) * (nb_words(str) + 1));
    int i = 0;
    int k = 0;

    for (int a = 0;i != nb_words(str);) {
        a = 0;
        while (is_good(str[k]) == 0 && str[k] != '\0')
            k += 1;
        new[i] = malloc(sizeof(char) * (nbr_letters(str, k) + 1));
        while (is_good(str[k]) == 1) {
            new[i][a] = str[k];
            a += 1;
            k += 1;
        }
        new[i][a] = '\0';
        i += 1;
    }
    new[i] = NULL;
    return (new);
}