#include "shell.h"

/**
 * sh_cd - changes the working directory of the shell.
 * @args: an array of the command and its arguments.
 * Return: 1 on success.
 */

int sh_cd(char **args)
{
	if (args[1] == NULL)
		error("expected argument to \"cd\"\n");
	else
		if (chdir(args[1]) != 0)
			perror("sh");
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
