#include "shell.h"

/**
 * sh_printenv - print the environment variables.
 * @args: arguments if any.
 * Return: 1 on success.
 */
int sh_printenv(char **args)
{
	int i = 0, j = 0;

	(void) args;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		if (j != 0)
			_putchar('\n');
		i++;
	}
	return (1);
}
/**
 * sh_cd - changes the working directory of the shell.
 * @args: an array of the command and its arguments.
 * Return: 1 on success.
 */

int sh_cd(char **args)
{
	char *home;

	if (args[1] == NULL)
	{
		home = _getenv("HOME");
		if (chdir(home) != 0)
		{
			perror("hsh");
			free(home);
		}
		else
			free(home);
	}
	else
		if (chdir(args[1]) != 0)
			perror("hsh");
	return (1);
}

/**
 * sh_exit - exits the shell program.
 * @args: arguments to the command.
 * Return: 0 always.
 */

int sh_exit(char **args)
{
	(void)(args);
	return (0);
}

/**
 * execute - execute built in commands or external commands.
 * @args: the command and its associated arguments to execute.
 * @av: an array of command line arguments passed to the program.
 * Return: 1 on success.
 */

int execute(char **args, char **av)
{
	int i;
	builtins commands[] = init;
	int num_commands = sizeof(commands) / sizeof(builtins);

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < num_commands; i++)
	{
		if (_strcmp(args[0], commands[i].name) == 0)
			return (commands[i].func(args));
	}
	return (launch(args, av));
}
