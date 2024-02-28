#include "shell.h"

/**
 * read_line - read a line of command from the command line.
 * Return: the line read.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t buff_size = 0;

	if (getline(&line, &buff_size, stdin) == -1)
	{
		if (read(0, line, 1) == 0)
			exit(EXIT_SUCCESS);
		else
		{
			free(line);
			error("Error reading command.");
		}
	}
	return (line);
}
