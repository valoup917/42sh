/*
** EPITECH PROJECT, 2020
** test_my_printf_part_four.c
** File description:
** test_my_printf_part_four.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(my_printf_char, basic, .init = cr_redirect_stdout)
{
    my_printf("%c", 'X');
    cr_assert_stdout_eq_str("X");
}

Test(my_printf_char_null, basic, .init = cr_redirect_stdout)
{
    my_printf("%s", NULL);
    cr_assert_stdout_eq_str("(null)");
}

Test(my_printf_d_neg, basic, .init = cr_redirect_stdout)
{
    my_printf("%d", -10);
    cr_assert_stdout_eq_str("-10");
}

Test(my_printf_o_null, basic, .init = cr_redirect_stdout)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_b_null, basic, .init = cr_redirect_stdout)
{
    my_printf("%b", 0);
    cr_assert_stdout_eq_str("0");
}