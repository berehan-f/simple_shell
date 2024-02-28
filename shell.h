#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define init {{"cd", &sh_cd}, {"exit", &sh_exit}}
extern char **environ;

int sh_exit(char **);
int sh_cd(char **);

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

void sh_loop_int(char **);
void sh_loop_noint(char **);
char *_getenv(const char *name);
char *read_line(void);
char *read_stream(void);
char **split_line(char *);
int execute(char **, char **);
int launch(char **, char **);
#endif
