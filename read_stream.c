#include "shell.h"
#define BUFF_SIZE 1024
/**
 * read_stream - reads a line of string from input stream.
 * Return: the string that is read.
 */

char *read_stream(void)
{
	unsigned int buff_size = BUFF_SIZE;
	unsigned int i = 0;
	char *line = malloc(sizeof(char) * buff_size);
	char ch;
	ssize_t count;

	if (line == NULL)
		error("sh: allocation error");
	while (1)
	{
		count = read(STDIN_FILENO, &ch, 1);
		if (count == -1)
			exit(EXIT_SUCCESS);
		else if (count == 0)
		{
			close(STDIN_FILENO);
			line[i] = '\0';
			return (line);
		}
		else if (ch == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = ch;
		i++;

		if (i >= buff_size)
		{
			line = _realloc(line, buff_size, buff_size + BUFF_SIZE);
			buff_size += BUFF_SIZE;
			if (line == NULL)
				error("sh: allocation error");
		}
	}
}
