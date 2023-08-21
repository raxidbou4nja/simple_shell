#include "libshell.h"


/**
 * cd_handler - Handle the cd command.
 * @token_count: number of tokens in the command.
 * @tokens: array of tokens containing the command and arguments.
 */

void cd_handler(int token_count, char *tokens[])
{
	const char *new_directory = (token_count > 1) ? tokens[1] : getenv("HOME");
	char cwd[INITIAL_BUFFER_SIZE];

	if (_strcmp(new_directory, "-") == 0)
	{
		new_directory = getenv("OLDPWD");
	}

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("OLDPWD", cwd, 1);
	}

	if (chdir(new_directory) == 0)
	{
		update_current_pwd();
	}
	else
	{
		perror("cd");
	}
}
