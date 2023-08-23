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
 * handle_exit_command - exit command from shell
 *
 * @tokens: array of tokens
 * @token_count: number of tokens
 *
 */

void handle_exit_command(char *tokens[], int token_count)
{
	int exit_status = EXIT_SUCCESS;
	int j;

	if (token_count > 1)
	{
		exit_status = _atoi(tokens[1]);
	}

	for (j = 0; j < token_count; j++)
		free(tokens[j]);
	exit(exit_status);
}


/**
 * update_current_pwd - to update Present Working Dir environment variable
 */
void update_current_pwd(void)
{
	char cwd[INITIAL_BUFFER_SIZE];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		_setenv("PWD", cwd, 1);
	}
}
