/*
** EPITECH PROJECT, 2021
** builtin_if
** File description:
** builtin_if
*/

#ifndef BUILTIN_IF_H_
#define BUILTIN_IF_H_

#include <stdbool.h>

bool str_is_alpha(char *str);
bool str_is_digit(char *str);
bool str_is_digit(char *str);
bool char_is_alpha(char c);
bool char_is_digit(char c);
bool char_is_digit(char c);

int builtins_manif(char **cmd, char *env[]);
void gl_builtin_manif(char *str);
int syntax_cmd_manif(char *str);
int syntax_error_manif(char **cmd, char *env[]);

#endif /* !BUILTIN_IF_H_ */