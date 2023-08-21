#include "libshell.h"

/**
 * print_environment - prints environment.
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
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
