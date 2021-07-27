/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** test_basic_nb
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

void  redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf, b_test , .init = redirect_all_std)
{
    my_printf("%b", 34);
    cr_assert_stdout_eq_str("100010");
}

Test(my_printf, s_test , .init = redirect_all_std)
{
    my_printf("%s", "tata toto");
    cr_assert_stdout_eq_str("tata toto");
}

Test(my_printf, c_test , .init = redirect_all_std)
{
    my_printf("%c", 'r');
    cr_assert_stdout_eq_str("r");
}

Test(my_printf, i_test , .init = redirect_all_std)
{
    my_printf("%i", 34);
    cr_assert_stdout_eq_str("34");
}