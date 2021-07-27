/*
** EPITECH PROJECT, 2020
** test_my_printf_part_one.c
** File description:
** test_my_printf_part_one
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(my_printf_six, basic, .init = cr_redirect_stdout)
{
    my_printf("%X", 10);
    cr_assert_stdout_eq_str("A");
}

Test(my_printf_seven, basic, .init = cr_redirect_stdout)
{
    my_printf("%X", 10);
    cr_assert_stdout_eq_str("A");
}

Test(my_printf_eight, basic, .init = cr_redirect_stdout)
{
    my_printf("%s", "Salut");
    cr_assert_stdout_eq_str("Salut");
}

Test(my_printf_nine, basic, .init = cr_redirect_stdout)
{
    my_printf("%S", "Sal\nut");
    cr_assert_stdout_eq_str("Sal\\012ut");
}

Test(my_printf_ten, basic, .init = cr_redirect_stdout)
{
    my_printf("%o", 10);
    cr_assert_stdout_eq_str("12");
}