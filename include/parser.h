/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <stddef.h>
#include <signal.h>
#include "just_shell.h"

typedef struct
{
    char *parser_end;
    char *parser_eof;
    short type;
    short id;
} parser_t;

typedef struct
{
    char *at;
    char *my;
} quote_t;

typedef struct siginfo
{
    int code;
    char *name;
    char *description;
} signal_message_t;

static const parser_t PARSER_ARRAY[] = {
    {" ", "", DELIMIT_NORMAL, DELIMIT_SPACE},
    {"\t", "", DELIMIT_NORMAL, DELIMIT_TAB},
    {"\"", "\"", DELIMIT_DELIMITER, DELIMIT_DQUOTE},
    {"'", "'", DELIMIT_DELIMITER, DELIMIT_SQUOTE},
    {"`", "`", DELIMIT_DELIMITER, DELIMIT_BQUOTE},
    {"(", ")", DELIMIT_DELIMITER, DELIMIT_PAR},
    {">&", "", DELIMIT_NORMAL, DELIMIT_REDIRECT},
    {">>", "", DELIMIT_GET, DELIMIT_DRIGHT},
    {">", "", DELIMIT_GET, DELIMIT_RIGHT},
    {"<<", "", DELIMIT_GET, DELIMIT_DLEFT},
    {"<", "", DELIMIT_GET, DELIMIT_LEFT},
    {"||", "", DELIMIT_SEP, DELIMIT_OR},
    {"&&", "", DELIMIT_SEP, DELIMIT_AND},
    {";", "", DELIMIT_SEP, DELIMIT_SEPARATOR},
    {"|", "", DELIMIT_GET, DELIMIT_PIPE},
    {"&", "", DELIMIT_GET, DELIMIT_BACKGROUND},
    {NULL, NULL, DELIMIT_WITHOUT, DELIMIT_WITHOUT},
};

static const signal_message_t SIGNAL_ARRAY[] = {
    {SIGABRT, "SIGABRT", "Abort signal"},
    {SIGALRM, "SIGALRM", "Timer signal"},
    {SIGBUS, "SIGBUS", "Bus error (bad memory access)"},
    {SIGCHLD, "SIGCHLD", "Child stopped or terminated"},
    {SIGCLD, "SIGCLD", "Child stopped or terminated"},
    {SIGCONT, "SIGCONT", "Continue if stopped"},
    {SIGFPE, "SIGFPE", "Floating exception"},
    {SIGHUP, "SIGHUP",
    "Hangup detected on controlling terminal or death of controlling process"},
    {SIGILL, "SIGILL", "Illegal Instruction"},
    {SIGINT, "SIGINT", "Interrupt from keyboard"},
    {SIGIO, "SIGIO", "I/O now possible"},
    {SIGIOT, "SIGIOT", "IOT trap: Abort signal"},
    {SIGKILL, "SIGKILL", "Kill signal"},
    {SIGPIPE, "SIGPIPE", "Broken pipe: write to pipe with no readers"},
    {SIGPOLL, "SIGPOLL", "Pollable event: I/O now possible"},
    {SIGPROF, "SIGPROF", "Profiling timer expired"},
    {SIGPWR, "SIGPWR", "Power failure"},
    {SIGQUIT, "SIGQUIT", "Quit from keyboard"},
    {SIGSEGV, "SIGSEGV", "Segmentation fault"},
    {SIGSTKFLT, "SIGSTKFLT", "Stack fault on coprocessor"},
    {SIGSTOP, "SIGSTOP", "Stop process"},
    {SIGTSTP, "SIGTSTP", "Stop typed at terminal"},
    {SIGSYS, "SIGSYS", "Bad system call "},
    {SIGTERM, "SIGTERM", "Termination signal"},
    {SIGTRAP, "SIGTRAP", "Trace/breakpoint trap"},
    {SIGTTIN, "SIGTTIN", "Terminal input for background process"},
    {SIGTTOU, "SIGTTOU", "Terminal output for background process"},
    {SIGURG, "SIGURG", "Urgent condition on socket "},
    {SIGUSR1, "SIGUSR1", "User-defined signal 1"},
    {SIGUSR2, "SIGUSR2", "User-defined signal 2"},
    {SIGVTALRM, "SIGVTALRM", "Virtual alarm clock "},
    {SIGXCPU, "SIGXCPU", "CPU time limit exceeded "},
    {SIGXFSZ, "SIGXFSZ", "File size limit exceeded"},
    {SIGWINCH, "SIGWINCH", "Window resize signal"},
    {0, NULL, NULL},
};

#define GET_MY_TYPE(x) (PARSER_ARRAY[x].type)
#define GET_MY_ID(x) (PARSER_ARRAY[x].id)
#define IF_SEPARATOR(x) ((GET_MY_TYPE(x) == DELIMIT_SEP) ? true : false)
#define IF_PIPE(x) ((GET_MY_ID(x) == DELIMIT_PIPE) ? true : false)

static const quote_t QUOTE_ARRAY[] = {
    {"\\a", "\a"},
    {"\\b", "\b"},
    {"\\t", "\t"},
    {"\\n", "\n"},
    {"\\v", "\v"},
    {"\\f", "\f"},
    {"\\r", "\r"},
    {NULL, NULL}
};

static const mykey_t KEY_ARRAY[] = {
    {"[A", KEY_UP},
    {"[B", KEY_DOWN},
    {"[D", KEY_LEFT},
    {"[C", KEY_RIGHT},
    {NULL, KEY_UNKNOWN},
};

typedef struct {
    char *rep;
    void (*func)(shell_t *);
} prompt_bn_t;

static const prompt_bn_t PROMPT_OPTIONS[] = {
    {"\\u", &sh_pp_user},
    {"\\v", &sh_pp_ver},
    {"\\W", &sh_pp_dir},
    {"\\l", &sh_pp_count_line},
    {"\\e", &sh_pp_get_ee},
    {"\\033", &sh_pp_get_ee},
    {"\\t", &sh_pp_get_time},
    {"$?", &sh_pp_rt_val},
    {"\\n", &sh_pp_eof},
    {NULL, NULL},
};

#endif /* !PARSER_H_ */
