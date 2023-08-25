#include "libshell.h"
#include <stdbool.h>

/**
 * main - entry point of the program.
 * @ac: number of command-line args.
 * @av: array of strings containing command-line args.
 *
 * Return: 0 on success, non-zero on failure.
 */

int main(int ac, char **av)
{
	char *command_line = NULL;
	size_t len = 0;
	ssize_t readbytes;
	int errori = 0;

	(void)ac;
	while (1)
	{
		char *tokens[MAX_TOKENS];
		int j, token_count = 0;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		readbytes = getline(&command_line, &len, stdin);
		if (readbytes == -1)
		{
			if (isatty(STDIN_FILENO))
				_putstr("\n");
			break;
		}
		token_count  = toknizer(command_line, tokens);
		if (token_count > 0 && !(_strcmp(tokens[0], ".") == 0
			|| _strcmp(tokens[0], "..") == 0))
		{
			if (_strcmp(tokens[0], "exit") == 0)
			{
				free(command_line);
				handle_exit_command(tokens, token_count);
			}
			else
			{
				command_handler(av, tokens, token_count, errori++);
				for (j = 0; j < token_count; j++)
					free(tokens[j]);
			}
		}
	}
	free(command_line);
	return (0);
}
