#include "libshell.h"

/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	char *command_line = NULL;
	size_t len = 0;
	ssize_t read;

	(void)argc;

	while (1)
	{
		char *tokens[INITIAL_BUFFER_SIZE / 2];
		int token_count, i;

		if (isatty(STDIN_FILENO)) {
			write(STDOUT_FILENO, "$ ", 2);
		}
		read = _getline(&command_line, &len);

		if (read == -1)
		{
			_putstr("\n");
			break;
		}

		token_count = tokenize_command(command_line, tokens);

		if (token_count > 0)
		{
			command_handler(argv[0], token_count, tokens);
		}

		for (i = 0; i < token_count; i++)
		{
			free(tokens[i]);
		}
	}

	free(command_line);
	return (0);
}
