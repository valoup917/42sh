/*
** EPITECH PROJECT, 2020
** test_my_printf_part_six.c
** File description:
** test_my_printf_part_six
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(my_printf_s_maj_long, basic, .init = cr_redirect_stdout)
{
    char str[5] = "TOTO";

    str[1] = 127;
    my_printf("%S", str);
    cr_assert_stdout_eq_str("T\\177TO");
}

Test(my_printf_s_maj_short, basic, .init = cr_redirect_stdout)
{
    char str[5] = "TOTO";

    str[1] = 6;
    my_printf("%S", str);
    cr_assert_stdout_eq_str("T\\006TO");
}

Test(my_printf_x_low, basic, .init = cr_redirect_stdout)
{
    my_printf("%x", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf_h_one, basic, .init = cr_redirect_stdout)
{
    my_printf("%#+x", 255);
    cr_assert_stdout_eq_str("0xff");
}

Test(my_printf_h_two, basic, .init = cr_redirect_stdout)
{
    my_printf("%+-6d", 75);
    cr_assert_stdout_eq_str("+75   ");
}