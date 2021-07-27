/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "enable_lib.h"
#include "just_shell.h"
#include "prototype.h"
#include "parser.h"
#include "builtins.h"
#include "read_line.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(init, test_empty)
{
    cr_assert_eq(0, 0);
}

Test(my_count_args_fct, simple_test)
{
    char *h[10] = {"salut", "salut", "salut", "salut", "salut", "salut",
        "salut", NULL};
    char *c[10] = {"salut", "salut", NULL};
    char *f[10] = {"salut", "salut", "salut", "salut", "salut", NULL};
    char *e[10] = {NULL};
    char *a[10] = {"salut", "salut", "salut", "salut", NULL};
    char *b[10] = {"salut", "salut", "salut", NULL};
    char *g[10] = {"salut", "salut", "salut", "salut", "salut", "salut", NULL};
    char *d[10] = {"salut", NULL};

    cr_assert_eq(count_args(a), 4);
    cr_assert_eq(count_args(b), 3);
    cr_assert_eq(count_args(c), 2);
    cr_assert_eq(count_args(d), 1);
    cr_assert_eq(count_args(e), 0);
    cr_assert_eq(count_args(f), 5);
    cr_assert_eq(count_args(g), 6);
    cr_assert_eq(count_args(e), 0);
    cr_assert_eq(count_args(h), 7);
}

Test(my_check_parenthesis_fct, simple_test)
{
    char *h[10] = {"foreach", "salut", "salut", "salut", "salut", "salut",
        "salut", NULL};
    char *c[10] = {"foreach", "salut", NULL};
    char *f[10] = {"foreach", "salut", "salut", "salut", "salut", NULL};
    char *e[10] = {NULL};
    char *a[10] = {"foreach", "salut", "salut", "salut", NULL};
    char *b[10] = {"foreach", "salut", "salut", NULL};
    char *g[10] = {"foreach", "salut", "salut", "salut", "salut", "salut", NULL};
    char *d[10] = {"foreach", NULL};

    cr_assert_eq(check_parenthesis(a), 4);
    cr_assert_eq(check_parenthesis(b), 3);
    cr_assert_eq(check_parenthesis(c), 2);
    cr_assert_eq(check_parenthesis(d), 1);
    cr_assert_eq(check_parenthesis(e), 0);
    cr_assert_eq(check_parenthesis(f), 5);
    cr_assert_eq(check_parenthesis(g), 6);
    cr_assert_eq(check_parenthesis(e), 0);
    cr_assert_eq(check_parenthesis(h), 7);
}