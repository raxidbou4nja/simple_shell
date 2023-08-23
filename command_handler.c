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
