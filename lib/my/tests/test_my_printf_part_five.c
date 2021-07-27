/*
** EPITECH PROJECT, 2020
** test_my_printf_part_five.c
** File description:
** test_my_printf_part_five
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(my_printf_x_long, basic, .init = cr_redirect_stdout)
{
    my_printf("%x", 741852);
    cr_assert_stdout_eq_str("b51dc");
}

Test(my_printf_x_long_maj, basic, .init = cr_redirect_stdout)
{
    my_printf("%X", 741852);
    cr_assert_stdout_eq_str("B51DC");
}

Test(my_printf_rec_printf, basic, .init = cr_redirect_stdout)
{
    my_printf("%d", my_printf("Count me"));
    cr_assert_stdout_eq_str("Count me8");
}

Test(my_printf_mult_fg, basic, .init = cr_redirect_stdout)
{
    my_printf("%s%%%d%s", "toto", 92, "tata");
    cr_assert_stdout_eq_str("toto%92tata");
}

Test(my_printf_bad_fg, basic, .init = cr_redirect_stdout)
{
    my_printf("%f");
    cr_assert_stdout_eq_str("%f");
}