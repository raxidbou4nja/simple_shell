#include "libshell.h"

/**
 * print_environment - prints environment.
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * exit_shell - Exit command from shell
 */

void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
