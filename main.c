#include "shell.h"

/**
 * main - the starting point of the shell program.
 * @ac: the number of command line arguments passed to the program.
 * @av: an array of command line arguments passed to the program.
 * Return: always 0 on success.
 */

int main(int ac, char **av)
{
	(void) ac;
	if (isatty(STDIN_FILENO) == 1)
		sh_loop_int(av);
	else
		sh_loop_noint(av);
	return (0);
}
