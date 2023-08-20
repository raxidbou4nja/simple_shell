#include "libshell.h"



/**
 * execute_command - execute a command with specified path and arguments
 *
 * @command_path: full path of the command to execute
 * @tokens: an array of command and arguments
 *
 * Return: function does not return a value.
 */

void execute_command(const char *command_path, char *tokens[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(command_path, tokens, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
