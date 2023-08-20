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

	}

	free(command_line);
	return (0);
}
