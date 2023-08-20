#include "libshell.h"

/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void)
{
	char *command_line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		char *tokens[INITIAL_BUFFER_SIZE / 2];
		int token_count, i;

		_putstr("$ ");
		fflush(stdout);
		read = _getline(&command_line, &len);

		if (read == -1)
		{
			_putstr("exiting terminal...\n");
			break;
		}

		token_count = tokenize_command(command_line, tokens);

		if (token_count > 0)
		{
			command_handler(token_count, tokens);
		}

		for (i = 0; i < token_count; i++)
		{
			free(tokens[i]);
		}
	}

	free(command_line);
	return (0);
}
