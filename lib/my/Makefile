##
## EPITECH PROJECT, 2020
## Makefile for printf
## File description:
## my_printf Makefile
##

NAME = libmy.a

SRCS =	srcs/my_printf_part_one.c			\
		srcs/my_printf_part_two.c			\
		srcs/my_printf_part_three.c			\
		srcs/my_printf_part_four.c			\
		srcs/my_printf_part_five.c			\
		srcs/my_printf_part_six.c			\
		srcs/my_printf_part_seven.c			\
		srcs/my_printf_part_eight.c			\
		srcs/my_printf_part_nine.c			\
		srcs/my_printf_part_ten.c			\
		lib_utility/my_conv_upper.c			\
		lib_utility/my_getnbr_base.c		\
		lib_utility/my_isneg.c				\
		lib_utility/my_putnbr_base.c		\
		lib_utility/my_str_to_word_array.c	\
		lib_utility/my_compute_power_rec.c	\
		lib_utility/my_compute_square_root.c	\
		lib_utility/my_find_prime_sup.c		\
		lib_utility/my_getnbr.c				\
		lib_utility/my_is_prime.c			\
		lib_utility/my_put_nbr.c			\
		lib_utility/my_revstr.c				\
		lib_utility/my_showmem.c			\
		lib_utility/my_showstr.c			\
		lib_utility/my_show_word_array.c	\
		lib_utility/my_sort_int_array.c		\
		lib_utility/my_strcapitalize.c		\
		lib_utility/my_strcat.c				\
		lib_utility/my_strcpy.c				\
		lib_utility/my_strdup.c				\
		lib_utility/my_str_isalpha.c		\
		lib_utility/my_str_islower.c		\
		lib_utility/my_str_isnum.c			\
		lib_utility/my_str_isprintable.c	\
		lib_utility/my_str_isupper.c		\
		lib_utility/my_strlowcase.c			\
		lib_utility/my_strncat.c			\
		lib_utility/my_strncmp.c			\
		lib_utility/my_strstr.c				\
		lib_utility/my_strupcase.c			\
		lib_utility/my_swap.c				\
		lib_utility/my_operator.c			\
		lib_utility/my_usage.c				\
		lib_utility/my_basic_ft.c			\
		lib_utility/my_sort.c				\
		lib_utility/my_get_next_line.c		\
		lib_utility/string/my_memccpy.c		\
		lib_utility/string/my_memchr.c		\
		lib_utility/string/my_memcmp.c		\
		lib_utility/string/my_memset.c		\
		lib_utility/string/my_strchr.c		\
		lib_utility/string/my_bzero.c		\
		lib_utility/string/my_memcpy.c		\
		lib_utility/string/my_calloc.c		\
		lib_utility/string/my_realloc.c		\


SRCSO =	srcs/my_printf_part_one.c			\
		srcs/my_printf_part_two.c			\
		srcs/my_printf_part_three.c			\
		srcs/my_printf_part_four.c			\
		srcs/my_printf_part_five.c			\
		srcs/my_printf_part_six.c			\
		srcs/my_printf_part_seven.c			\
		srcs/my_printf_part_eight.c			\
		srcs/my_printf_part_nine.c			\
		srcs/my_printf_part_ten.c			\

SRCST = tests/test_my_printf_part_one.c		\
		tests/test_my_printf_part_two.c		\
		tests/test_my_printf_part_three.c	\
		tests/test_my_printf_part_four.c	\
		tests/test_my_printf_part_five.c	\
		tests/test_my_printf_part_six.c		\

OBJS = ${SRCS:.c=.o}
HEADER = ./include

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

%.o:%.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} *gc*

fclean:		clean
			${RM} ${NAME} unit_tests

re:			fclean all

tests_run:
			make re -C .
			${CC} ${SRCSO} ${SRCST} -I ${HEADER} -L . -lmy -lcriterion --coverage -o unit_tests
			./unit_tests
