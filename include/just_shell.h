/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** just_shell
*/

#ifndef JUST_SHELL_H_
#define JUST_SHELL_H_

#include <sys/types.h>
#include <stdbool.h>
#include "enable_lib.h"

typedef enum {
    PIPE_FD_IN = 0,
    PIPE_FD_OUT = 1
} pipe_fd_t;

typedef enum {
    REDIRECT_RIGHT = 0,
    REDIRECT_TRIGHT = 1,
    REDIRECT_LEFT = 2,
    REDIRECT_TLEFT = 3
} parser_redirect_t;

typedef enum {
    DELIMIT_WITHOUT = -1,
    DELIMIT_SPACE = 0,
    DELIMIT_TAB = 1,
    DELIMIT_DQUOTE = 2,
    DELIMIT_SQUOTE = 3,
    DELIMIT_BQUOTE = 4,
    DELIMIT_PAR = 5,
    DELIMIT_REDIRECT = 6,
    DELIMIT_DRIGHT = 7,
    DELIMIT_RIGHT = 8,
    DELIMIT_DLEFT = 9,
    DELIMIT_LEFT = 10,
    DELIMIT_OR = 11,
    DELIMIT_AND = 12,
    DELIMIT_SEPARATOR = 13,
    DELIMIT_PIPE = 14,
    DELIMIT_BACKGROUND = 15,
} parser_delimiter_t;

typedef enum {
    DELIMIT_NORMAL = 0,
    DELIMIT_DELIMITER = 1,
    DELIMIT_GET = 2,
    DELIMIT_SEP = 3
} parser_delimiter_instance_t;

typedef struct cmd_s {
    char *commands;
    short command_end_idx;
    struct cmd_s *next;
    struct cmd_s *prev;
} cmd_t;

typedef struct pipe_s {
    pid_t pipe_pid;
    cmd_t *pipe_cmd;
    int ac;
    char **av;
    char *pipe_path;
    int fd[2];
    char *redirection[4];
    struct pipe_s *next;
    struct pipe_s *prev;
} pipe_t;

typedef struct list_s {
    cmd_t *list_cmd;
    pipe_t *p;
    short list_sep;
    bool list_threat;
    bool list_bg;
    struct list_s *next;
    struct list_s *prev;
} list_t;

typedef struct alias_s {
    char **alias_find;
    char **alias_redi;
    struct alias_s *next;
    struct alias_s *prev;
} alias_t;

typedef struct lcl_s {
    char *lcl_name;
    char *lcl_value;
    struct lcl_s *next;
    struct lcl_s *prev;
} lcl_t;

typedef struct {
    pid_t pid;
    pid_t pgid;
} sh_pid_t;

typedef struct previous_s {
    unsigned id;
    char *str;
    time_t prev_date;
    struct previous_s *next;
    struct previous_s *prev;
} previous_t;

typedef struct jobs_s {
    unsigned id;
    char *name;
    pid_t pid;
    struct jobs_s *next;
    struct jobs_s *prev;
} jobs_t;

typedef struct {
    bool sh_wr;
    int fd[2];
    int sh_rt;
    sh_pid_t pid;
    char *oldpwd;
    char **sh_array;
    char **sh_path;
    lcl_t *lcl;
    cmd_t *commands;
    list_t *list;
    pipe_t *pipe;
    alias_t *alias;
    jobs_t *jobs;
    previous_t *history;
    bool actual_exit;
} shell_t;

typedef struct {
    char *replace;
    void (*func)(shell_t *);
} prompt_t;

#include "prototype.h"

#define TOO_MANY_ARG "%s: Too many arguments.\n"
#define TOO_FEW_ARG "%s: Too few arguments.\n"
#define NO_FOLDER "%s: Not a directory.\n"
#define NO_PERMIT "%s: Permission denied.\n"
#define IS_BUILTIN "%s: shell built-in command.\n"
#define IS_BUILTIN_WITH "%s is a shell built-in\n"

#define ERROR_FUNCTION "Error: %s function failled.\n"
#define ERROR_NOT_FOUND "%s: Command not found.\n"
#define ERROR_NO_MATCH "%s: No match.\n"
#define ERROR_NO_FILE "%s: No such file or directory.\n"
#define ERROR_NOT_FOLDER "%s: Not a directory.\n"

#define ERROR_NO_SCRIPT "%s: Aucun fichier ou dossier de ce type.\n"

#define ERROR_ALLOW "%s: Permission denied.\n"
#define ERROR_FORMAT "%s: Exec format error. Wrong Architecture.\n"

#define MESS_SUSPENDED "\r[%u]\t+ %d Suspended\t%s\n"
#define MESS_CTRLD "Use \"exit\" to leave %s.\n"

#endif /* !JUST_SHELL_H_ */
