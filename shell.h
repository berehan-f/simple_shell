#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/** globals and macros */
#define init {{"cd", &sh_cd}, {"exit", &sh_exit}, {"env", &sh_printenv}}
extern char **environ;

/**
 * struct builtins - contains info about the shell builtin functions.
 * @name: name of shell builtin command.
 * @func: a fucntion that implements the builtin command.
 */
typedef struct builtins
{
	char *name;
	int (*func)(char **);
} builtins;

/** utilities */
void error(char *);
void *_realloc(void *ptr, unsigned int, unsigned int);
char *_strdup(char *);
int _strcmp(char *, char *);
int _putchar(char c);

void sh_loop_int(char **);
void sh_loop_noint(char **);
char *_getenv(const char *name);
char *read_line(void);
char *read_stream(void);
char **split_line(char *);
int execute(char **, char **);
int launch(char **, char **);

/** builtin commands */
int sh_exit(char **);
int sh_cd(char **);
#endif
