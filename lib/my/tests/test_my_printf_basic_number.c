/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** test_my_printf_basic_number
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

void  redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf, o_test , .init = redirect_all_std)
{
    my_printf("%o", 10);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, _test , .init = redirect_all_std)
{
    my_printf("%s", "34");
    cr_assert_stdout_eq_str("34");
}

Test(my_printf, modulo_test , .init = redirect_all_std)
{
    my_printf("%%", "34");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, ofail_tests , .init = redirect_all_std)
{
    my_printf("%o", 10);
    cr_assert_stdout_eq_str("12");
}