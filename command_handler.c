#include "libshell.h"

/**
 * command_handler - handle command with functions.
 * @token_count: token length
 * @tokens: array of tokens
 * @exec_file_name: execution file name
 * @errori: error counter
 */

void command_handler(char *exec_file_name[],
	char *tokens[],
	int token_count,
	int errori)
{
	int i;

	for (i = 0; i < token_count; i++)
	{
		if (_strcmp(tokens[i], "$$") == 0)
		{
			snprintf(tokens[i], MAX_TOKENS, "%d", getpid());
		}
	}
	if (token_count > 0 && tokens[0][0] == '#')
		return;
	if ((_strcmp(tokens[0], "env") == 0) && token_count == 1)
	{
		print_environment();
	}
	else if (_strcmp(tokens[0], "cd") == 0)
	{
		cd_handler(token_count, tokens);
	}
	else
	{
		command_executioner(exec_file_name[0], tokens, errori);
	}
}
