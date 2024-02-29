#include "shell.h"

/**
 * sh_loop_int - a loop that reads, interprets and execute commands.
 *           for interactive terminal session.
 * @av: an array of command line arguments passed to the program.
 */

void sh_loop_int(char **av)
{
	char *line;
	char **args;
	int status;

	do {
		write(1, "#cisfun$ ", 9);
		line = read_line();
		args = split_line(line);
		status = execute(args, av);
		free(line);
		free(args);
	} while (status);
}
/**
 * sh_loop_noint - a loop that reads, interprets and execute commands
 *                 for a non interactive program session.
 * @av: an array of command line arguments passed to the program.
 */
void sh_loop_noint(char **av)
{
	char *line;
	char **args;
	int status;

	do {
	line = read_stream();
	args = split_line(line);
	status = execute(args, av);
	free(line);
	free(args);
	} while (status);
}
