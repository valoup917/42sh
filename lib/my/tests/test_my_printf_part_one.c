/*
** EPITECH PROJECT, 2020
** test my printf
** File description:
** my printf part one
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(my_printf_one, basic, .init = cr_redirect_stdout)
{
    my_printf("TEST_ONE");
    cr_assert_stdout_eq_str("TEST_ONE");
}

Test(my_printf_two, basic, .init = cr_redirect_stdout)
{
    my_printf("%d", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf_three, basic, .init = cr_redirect_stdout)
{
    my_printf("%i", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf_four, basic, .init = cr_redirect_stdout)
{
    my_printf("%u", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf_five, basic, .init = cr_redirect_stdout)
{
    my_printf("%x", 10);
    cr_assert_stdout_eq_str("a");
}