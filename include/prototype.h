/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include "just_shell.h"
#include "read_line.h"

int sizeof_array_sh(char **ar);
void utils_array_cat(char **ar, char **dp);
void utils_array_mcat(char **ar, char **dp);
bool utils_compare_array(char **ar, char **dp, int n);
bool utils_free_array(char **ar);

char *builtins_getenv(char **ar, char *s);
int builtins_getenv_id(char **ar, char *s);
char *builtins_find_getenv(char **ar, char *s);
void utils_cmd_dlist(cmd_t *cmd);
int utils_parsing_cnt_opt(char *s);
cmd_t *utils_cmd_radd(cmd_t *cmd, char *s, short i);
void utils_pipe_dcmd(pipe_t *p, cmd_t *cmd);
char *utils_parsing_get_opt(char *s);
char *utils_parsing_find_element(shell_t *sh, char *s);
char *utils_realloc_string(char *s, char *d);
char *utils_parsing_end_of_line(char *msg, char c);
char *util_get_environ_path(cmd_t *cmd);

char *utils_get_variable(shell_t *sh, cmd_t *cmd);
char **utils_al_change(shell_t *sh, char **av, bool check);
bool shell_globling(pipe_t *p);
void utils_pipe_dlist(pipe_t *p);

short parser_end_of_type(char *s, int *n);
char **end_p2(char **tmp, char *variable, char **test, int a);
cmd_t *utils_cmd_move_back(cmd_t *cmd);
cmd_t *parser_cmd_comment(cmd_t *cmd);
void parser_cmd_bslash(cmd_t *cmd);
void parser_cmd_dquote(cmd_t *cmd);
cmd_t *parser_cmd_historyp(shell_t *sh, cmd_t *cmd, char *s);
list_t *utils_linked_list_ar(list_t *ls, cmd_t *cmd, short ts);
void utils_cmd_pnode(cmd_t *cmd);
list_t *utils_linked_list_move_back(list_t *ls);
void parser_cmd_hist(shell_t *sh, cmd_t *cmd);
bool parser_find_sep(shell_t *sh);
bool parser_bg(shell_t *sh);
void free_sh_cmd(shell_t *sh);
void utils_cmd_dnode(shell_t *sh, cmd_t *cmd);
bool parser_check_len_max(shell_t *sh);
bool parser_del_more(shell_t *sh);
void parser_sep_tmp_quotes_threat(char *s);
char *utils_hs(shell_t *sh, char *s);
bool parser_bg_cmd_tmp(pipe_t *p, list_t *ll, shell_t *sh);
void utils_linked_list_dlist(list_t *ls);
lcl_t *utils_lcl_fnode(char *s, lcl_t *lcl);
lcl_t *utils_lcl_al(char *r[2], lcl_t *lcl);
void parser_cmd_tmp_nrm(char *s);
void parser_cmd_pp(cmd_t *cmd);
bool parser_redirection(list_t *ll);
pipe_t *utils_pipe_mouvement_back(pipe_t *p);
pipe_t *utils_pipe_ar(pipe_t *p, cmd_t *cmd);
bool sh_parser(shell_t *sh, char *s, bool check);

char **my_str_to_word_array_gl(char *s, char c);

bool sh_parser_global(shell_t *sh, char *s);
bool sh_linked_thread(shell_t *sh);
void shell_status_close(shell_t *sh, unsigned char status);
bool utils_alias_bonus_exec(shell_t *sh, char *s);
previous_t *utils_hs_ar(previous_t *h, char *s);
void sh_pp_nb(shell_t *sh);
const char *read_line_line(int fd, const mykey_t *key);
void read_line_free(void);
bool shell_redi_status(shell_t *sh, pipe_t *p, int *fd);
void shell_prdi_error(pipe_t *p);
bool shell_tmp_access(char *s);
char *shell_tmpt_fprg(shell_t *sh, char *s);
char **utils_array_copy(char **ar);
void sh_init_ushell_pass(shell_t *sh);
bool sh_init_ushell(shell_t *sh);

void sh_pp_dir(shell_t __attribute__ ((unused)) *sh);
void sh_pp_count_line(shell_t __attribute__ ((unused)) *sh);
void sh_pp_rt_val(shell_t __attribute__ ((unused)) *sh);
void sh_pp_ver(shell_t __attribute__ ((unused)) *sh);
void sh_pp_user(shell_t __attribute__ ((unused)) *sh);
void sh_pp_get_time(shell_t __attribute__ ((unused)) *sh);
void sh_pp_get_ee(shell_t __attribute__ ((unused)) *sh);

jobs_t *utils_jb_rmove(jobs_t *jb, char *s, pid_t pid);
void shell_prdi_error_open(shell_t *sh, pipe_t *p);
int sh_get_par(shell_t *sh, pipe_t *p);
bool utils_cmd_array(shell_t *sh, pipe_t *p);
pid_t tmp_sh_thread_cmd(shell_t *sh, pipe_t *p, pid_t pgid);
void shell_replace_groups(pid_t pid);
int shell_signal_status(int st);
cmd_t *sh_bq_fork(shell_t *sh, pipe_t *p, cmd_t *cmd);
void shell_init_prompt_error(void);

int builtins_end(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh);
void signal_display_error(int status);
void utils_jb_dnode(shell_t *sh, jobs_t *jb);
void utils_lcl_dlist(lcl_t *lcl);
void utils_al_del_list(alias_t *al);
void utils_jb_dlist(shell_t *sh, jobs_t *jb);
void utils_hs_dlist(previous_t *h);
void get_sh_sig(bool check);
bool shell_initialisation(shell_t *sh, int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, char **arr);
bool sh_open_folder(shell_t *sh);
bool sg_cmd_get(shell_t *sh);
bool sg_cmd_get_mou_mou(shell_t *sh);
bool sh_scriptings(shell_t *sh, int ac, char **av);

int builtins_alias(int ac, char **av, shell_t *sh);
int builtins_env(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh);
int builtins_execution(shell_t *sh, pipe_t *p);
int builtins_exit(int ac, char **av, shell_t *sh);
int builtins_history(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh);
void sh_command_control(shell_t *sh, char *s);
int builtins_setenv(int ac, char **av, shell_t *sh);
pid_t sh_thread_ptry(shell_t *sh, pipe_t *p);
void sh_thread_pwait(shell_t *sh, list_t *ll, pipe_t *p, pid_t pgid);
short check_builtins(char *s);
char *sh_path_env(shell_t *sh, char *s);
bool shell_aredi_dp(shell_t *sh, pipe_t *p);
bool sh_parser_pipe(shell_t *sh);
void sh_bq_all(shell_t *sh, pipe_t *p);
int builtins_unsetenv(int ac, char **av, shell_t *sh);
int builtins_cd(int ac, char **av, shell_t *sh);
char **utils_array_delete_node(char **ar, char *s);
char **utils_alloc_array(char **ar, char *s);
previous_t *utils_hs_back(previous_t *p);
bool utils_alias_bonus_set(shell_t *sh, char **av);
char **utils_strdup_2d_array(char **array);
char **utils_remplace_alias(alias_t *alias, char **av);
void utils_tri_alias(shell_t *alias);
alias_t *utils_al_lnode(alias_t *al, char **avo, char **avt);
int builtins_builtins(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh);

int executable(char **argv, shell_t *sh);
char **my_stwa(char *str);
int check_errors_foreach(int ac, char **argv, shell_t *sh);
int builtins_repeat(int ac, char **argv, shell_t *sh);
int builtins_foreach(int __attribute__ ((unused)) ac, char **argv, shell_t *sh);

void print_2d_array(char **array);
int compare_str_2d_array(char *str, char **array);
int builtins_where(int __attribute__ ((unused)) ac, char **str,
shell_t *alias);
int builtins_which(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **str, shell_t __attribute__ ((unused)) *alias);
int builtins_fg(int ac, char **av, shell_t *sh);
jobs_t *utils_jb_move_back(jobs_t *jb);
int builtins_jobs(int __attribute__ ((unused)) ac,
char __attribute__ ((unused)) **av, shell_t *sh);

void refresh_wait(void);

int builtins_set_utils_tmp(char **array, char *av[2]);
int builtins_set_utils(char **array);
int builtins_set(int __attribute__ ((unused)) ac, char **av, shell_t *sh);
void sh_pp_eof(shell_t __attribute__ ((unused)) *sh);
int builtins_help(int ac, char **av, shell_t *sh);

int count_args(char **argv);
int check_parenthesis(char **argv);
int check_variable(char **argv);

#endif /* !PROTOTYPE_H_ */
