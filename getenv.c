#include <string.h>
#include "shell.h"

/**
 * _getenv - get the value of a given environmnent variable.
 * @name: the variable to get the value of.
 * Return: the value of the variable.
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token;
	char *line;

	while (environ[i])
	{
		line = _strdup(environ[i]);
		token = strtok(line, "=");
		if (_strcmp(token, (char *)name) == 0)
		{
			token = _strdup(strtok(NULL, "="));
			free(line);
			return (token);
		}
		free(line);
		i++;
	}
	return (NULL);
}
