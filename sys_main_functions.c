#include "libshell.h"

/**
  *execute_with_path - executes a command by specifying its path
 *
  *@tokens: An array of command and arguments
 *
  *Return: On success, returns 0.
  *On failure, returns an appropriate error code.
 */

int execute_with_path(char *tokens[])
{
	if (access(tokens[0], X_OK) == 0)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{

			execve(tokens[0], tokens, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}

		return (1);
	}
	else
	{
		printf("Command '%s' not found or not executable.\n", tokens[0]);
		return (0);
	}
}