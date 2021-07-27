##
## EPITECH PROJECT, 2021
## B-PSU-210-PAR-2-1-42sh-yoel.edery
## File description:
## Makefile
##

NAME 		=	42sh

SRCS 		=	src/shell/shell_part_five.c	\
				src/shell/shell_part_six.c	\
				src/shell/shell_part_redi.c	\
				src/shell/shell_cmd.c	\
				src/shell/shell_pp_func_prompt_part_two.c	\
				src/shell/shell_globling.c	\
				src/shell/shell_part_two.c	\
				src/shell/shell_part_three.c	\
				src/shell/shell_initialisation.c	\
				src/shell/shell_bonus_prompt.c	\
				src/shell/shell_part_one.c	\
				src/shell/shell_pp_func_part_one.c	\
				src/shell/shell_part_four.c	\
				src/parser/parser_end.c	\
				src/parser/paser_sep.c	\
				src/parser/parser_sep_part_three.c	\
				src/parser/parser_redirection.c	\
				src/parser/parser_bg.c	\
				src/parser/parser_sep_part_two.c	\
				src/parser/parser_redirection_part_two.c	\
				src/utility/read_line/read_line_mouvement_part_two.c	\
				src/utility/read_line/read_line_init_history.c	\
				src/utility/read_line/read_line_add_char.c	\
				src/utility/read_line/read_line_mouvement_part_three.c	\
				src/utility/read_line/read_line_mouvement_key.c	\
				src/utility/read_line/read_line_mouvements.c	\
				src/utility/read_line/read_line_mouvement_array.c	\
				src/utility/signal_char/signal_key.c	\
				src/utility/signal_char/signal_char.c	\
				src/utility/shell_utility/utils_alias_part_three.c	\
				src/utility/shell_utility/utils_history_part_two.c	\
				src/utility/shell_utility/utils_array_cmd.c	\
				src/utility/shell_utility/utils_cmd_move_two.c	\
				src/utility/shell_utility/utils_lcl_part_one.c	\
				src/utility/shell_utility/utils_linked_list.c	\
				src/utility/shell_utility/utils_changing_array.c	\
				src/utility/shell_utility/utils_tab_part_two.c	\
				src/utility/shell_utility/utils_split.c	\
				src/utility/shell_utility/utils_jobs_shell.c	\
				src/utility/shell_utility/utils_array.c	\
				src/utility/shell_utility/utils_variable.c	\
				src/utility/shell_utility/utils_tab.c	\
				src/utility/shell_utility/utils_alias_checking.c	\
				src/utility/shell_utility/utils_cmd_move.c	\
				src/utility/shell_utility/utils_path.c	\
				src/utility/shell_utility/utils_signal.c	\
				src/utility/shell_utility/utils_free_history.c	\
				src/utility/history/history.c	\
				src/main.c	\
				src/builtins/builtins_getenv.c	\
				src/builtins/builtins_cd.c	\
				src/builtins/builtins_alias.c	\
				src/builtins/builtins_env.c	\
				src/builtins/builtins_setenv.c	\
				src/builtins/builtins_unsetenv.c	\
				src/builtins/builtins_where.c	\
				src/builtins/builtins_which.c	\
				src/builtins/builtins_jobs.c	\
				src/builtins/builtins_end.c	\
				src/builtins/builtins_set.c	\
				src/builtins/builtins_set_part_two.c	\
				src/builtins/builtins_foreach.c	\
				src/builtins/builtins_executions.c	\
				src/builtins/builtins_foreach_part_two.c	\
				src/builtins/builtins_foreach_part_three.c	\
				src/builtins/builtins_foreach_part_four.c	\
				src/builtins/builtins_repeat.c	\
				src/builtins/builtins_help.c	\

SRC_TESTS =		src/shell/shell_part_five.c	\
				src/shell/shell_part_six.c	\
				src/shell/shell_part_redi.c	\
				src/shell/shell_cmd.c	\
				src/shell/shell_pp_func_prompt_part_two.c	\
				src/shell/shell_globling.c	\
				src/shell/shell_part_two.c	\
				src/shell/shell_part_three.c	\
				src/shell/shell_initialisation.c	\
				src/shell/shell_bonus_prompt.c	\
				src/shell/shell_part_one.c	\
				src/shell/shell_pp_func_part_one.c	\
				src/shell/shell_part_four.c	\
				src/parser/parser_end.c	\
				src/parser/paser_sep.c	\
				src/parser/parser_sep_part_three.c	\
				src/parser/parser_redirection.c	\
				src/parser/parser_bg.c	\
				src/parser/parser_sep_part_two.c	\
				src/parser/parser_redirection_part_two.c	\
				src/utility/read_line/read_line_mouvement_part_two.c	\
				src/utility/read_line/read_line_init_history.c	\
				src/utility/read_line/read_line_add_char.c	\
				src/utility/read_line/read_line_mouvement_part_three.c	\
				src/utility/read_line/read_line_mouvement_key.c	\
				src/utility/read_line/read_line_mouvements.c	\
				src/utility/read_line/read_line_mouvement_array.c	\
				src/utility/signal_char/signal_key.c	\
				src/utility/signal_char/signal_char.c	\
				src/utility/shell_utility/utils_alias_part_three.c	\
				src/utility/shell_utility/utils_history_part_two.c	\
				src/utility/shell_utility/utils_array_cmd.c	\
				src/utility/shell_utility/utils_cmd_move_two.c	\
				src/utility/shell_utility/utils_lcl_part_one.c	\
				src/utility/shell_utility/utils_linked_list.c	\
				src/utility/shell_utility/utils_changing_array.c	\
				src/utility/shell_utility/utils_tab_part_two.c	\
				src/utility/shell_utility/utils_split.c	\
				src/utility/shell_utility/utils_jobs_shell.c	\
				src/utility/shell_utility/utils_array.c	\
				src/utility/shell_utility/utils_variable.c	\
				src/utility/shell_utility/utils_tab.c	\
				src/utility/shell_utility/utils_alias_checking.c	\
				src/utility/shell_utility/utils_cmd_move.c	\
				src/utility/shell_utility/utils_path.c	\
				src/utility/shell_utility/utils_signal.c	\
				src/utility/shell_utility/utils_free_history.c	\
				src/utility/history/history.c	\
				src/builtins/builtins_getenv.c	\
				src/builtins/builtins_cd.c	\
				src/builtins/builtins_alias.c	\
				src/builtins/builtins_env.c	\
				src/builtins/builtins_setenv.c	\
				src/builtins/builtins_unsetenv.c	\
				src/builtins/builtins_where.c	\
				src/builtins/builtins_which.c	\
				src/builtins/builtins_jobs.c	\
				src/builtins/builtins_end.c	\
				src/builtins/builtins_set.c	\
				src/builtins/builtins_set_part_two.c	\
				src/builtins/builtins_foreach.c	\
				src/builtins/builtins_executions.c	\
				src/builtins/builtins_foreach_part_two.c	\
				src/builtins/builtins_foreach_part_three.c	\
				src/builtins/builtins_foreach_part_four.c	\
				src/builtins/builtins_repeat.c	\
				src/builtins/builtins_help.c	\
				tests/test.c	\


HEADER_LIB 	=	./lib/my/include
HEADER 		=	./include
LIB 		=	./lib/my
OBJS 		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-I ${HEADER}
CFLAGS		+=	-I ${HEADER_LIB}
LDFLAGS		=	-L ${LIB} -lmy

all:		lib ${NAME}

lib:
		make -C ./lib/my

${NAME}:	${OBJS}
		${CC} ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
		make clean -C ./lib/my
		${RM} ${OBJS} *.*gc*

fclean:		clean
		make fclean -C ./lib/my
		${RM} ${NAME} unit_tests

re:			fclean all

tests_run: all
		gcc -o unit_tests $(SRC_TESTS) $(LDFLAGS) $(CFLAGS) --coverage -lcriterion
		./unit_tests


.PHONY: all lib clean fclean re
