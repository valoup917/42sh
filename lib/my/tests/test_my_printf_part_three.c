/*
** EPITECH PROJECT, 2020
** test_my_printf_part_three.c
** File description:
** test_my_printf_part_three
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(my_printf_eleven, basic, .init = cr_redirect_stdout)
{
    my_printf("%p", 10);
    cr_assert_stdout_eq_str("0xa");
}

Test(my_printf_twelve, basic, .init = cr_redirect_stdout)
{
    my_printf("%p", NULL);
    cr_assert_stdout_eq_str("(nil)");
}

Test(my_printf_thirteen, basic, .init = cr_redirect_stdout)
{
    my_printf("%b", 42);
    cr_assert_stdout_eq_str("101010");
}

Test(my_printf_thourteen, basic, .init = cr_redirect_stdout)
{
    my_printf("Test %s %d %i %u %x %X %S %b %o %p",
        "HELlO", 10, 10, 10, 10, 10, "re\nre", 10, 10, 10);
    cr_assert_stdout_eq_str("Test HELlO 10 10 10 a A re\\012re 1010 12 0xa%");
}

Test(my_printf_fifeteen, basic, .init = cr_redirect_stdout)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}