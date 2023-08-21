#include "libshell.h"

/**
 * command_handler - handle command with functions.
 * @token_count: token length
 * @tokens: array of tokens
 *
 * Return: 0 if similar 1 if not
 */

void command_handler(const char *exec_file_name, int token_count, char *tokens[])
{
	int executed;
	int exit_status;

	if ((_strcmp(tokens[0], "env") == 0) && token_count == 1)
	{
		print_environment();
		return;
	}

	if ((_strcmp(tokens[0], "exit") == 0))
	{
		if (token_count == 1)
		{
			exit_shell();
		}

		exit_status = _atoi(tokens[1]);
		exit(exit_status);
		return;
	}


	if (_strcmp(tokens[0], "cd") == 0)
	{
		cd_handler(token_count, tokens);
		return;
	}

	executed = execute_without_path(exec_file_name, tokens[0], tokens);

	if (executed)
	{
		return;
	}

	executed = execute_with_path(exec_file_name, tokens);
}
