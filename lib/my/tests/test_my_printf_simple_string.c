/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** test_simple_string
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my_printf.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf , simple_string , .init = redirect_all_std)
{
    my_printf("hello  world");
    cr_assert_stdout_eq_str("hello  world");
}

Test(my_printf, medium_string , .init = redirect_all_std)
{
    my_printf("hello world 45");
    cr_assert_stdout_eq_str("hello world 45");
}

Test(my_printf, d_tests , .init = redirect_all_std)
{
    my_printf("Bobjour j'ai %d amis", 45);
    cr_assert_stdout_eq_str("Bobjour j'ai 45 amis");
}

Test(my_printf, x_tests , .init = redirect_all_std)
{
    my_printf("Bobjour j'ai %x amis et %p coco", 45, 45);
    cr_assert_stdout_eq_str("Bobjour j'ai 2d amis et 0x2d coco");
}