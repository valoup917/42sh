/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** test_advance_string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf, hard_test , .init = redirect_all_std)
{
    my_printf("%s%d%c", "je suis chaud", 44, 'a');
    cr_assert_stdout_eq_str("je suis chaud44a");
}

Test(my_printf, hardest_test , .init = redirect_all_std)
{
    my_printf("caca %d j'ai fais %c pipi et sotises %X", 3, 'r', 45);
    cr_assert_stdout_eq_str("caca 3 j'ai fais r pipi et sotises 2D");
}

Test(my_printf, x_test , .init = redirect_all_std)
{
    my_printf("%u", 34);
    cr_assert_stdout_eq_str("34");
}

Test(my_printf, p_test , .init = redirect_all_std)
{
    my_printf("%p", 45);
    cr_assert_stdout_eq_str("0x2d");
}