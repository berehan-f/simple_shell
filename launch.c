#include "shell.h"

/**
 * launch - launchs external command using execv.
 * @args: an array of string that contain command and arguments.
 * @av: an array of command line arguments passed to the program.
 * Return: 1 on success.
 */

int launch(char **args, char **av)
{
	pid_t pid;
	int pid_status;

	pid = fork();
	if (pid == -1)
		error("Can't fork process:");
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			error(av[0]);
	}
	else
	{
		do {
			pid_status = waitpid(pid, &pid_status, 0);
		} while (!WIFEXITED(pid_status) && !WIFSIGNALED(pid_status));
	}
	return (1);
}
