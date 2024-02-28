#include <string.h>
#include "shell.h"
#define BUFF_SIZE 10

/**
 * split_line - split a line from the command interface to its
 *              respective command and arguments.
 * @s: the line to split to command and arguments.
 * Return: the command and its respective arguments if there are any.
 */

char **split_line(char *s)
{
	unsigned int i = 0, buff_size = BUFF_SIZE;
	const char *delim = " \a\t\r\n";
	char **args = malloc(buff_size * sizeof(char *));
	char *token;

	if (args == NULL)
		error("Can't allocate buffer");

	token = strtok(s, delim);
	while (token != NULL)
	{
		args[i++] = token;
		if (i >= buff_size)
		{
			args = _realloc(args, buff_size, buff_size + BUFF_SIZE);
			if (args == NULL)
				error("Can't allocate buffer");
			buff_size += BUFF_SIZE;
		}
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}
