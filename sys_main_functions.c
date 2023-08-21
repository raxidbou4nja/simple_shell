#include "libshell.h"

/**
  *execute_with_path - executes a command by specifying its path
 *
  *@tokens: An array of command and arguments
 *
  *Return: On success, returns 0.
  *On failure, returns an appropriate error code.
 */

int execute_with_path(char *tokens[])
{
	if (access(tokens[0], X_OK) == 0)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{

			execve(tokens[0], tokens, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}

		return (1);
	}
	else
	{
		printf("Command '%s' not found or not executable.\n", tokens[0]);
		return (0);
	}
}

/**
  *execute_without_path - executes a command without specifying its path
  *
  *@command: The full path to the command
  *@tokens: An array of command and arguments
  *
  *Return: On success, returns 0.
  *On failure, returns an appropriate error code.
 */

int execute_without_path(char *command, char *tokens[])
{
	char *command_path = find_executable(command);

	if (command_path != NULL)
	{
		execute_command(command_path, tokens);
		free(command_path);
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
  *_getline - read a line from input stream with dynamic memory allocation
  *
  *@lineptr: pointer to the buffer where the line is stored
  *@n: pointer to the size of the allocated buffer
 *
  *Return: On success, returns the number of characters read
 */

ssize_t _getline(char **lineptr, size_t *n)
{
	static char buffer[INITIAL_BUFFER_SIZE];
	static size_t buffer_index;
	static size_t bytes_read;
	size_t line_length;

	if (*lineptr == NULL || *n == 0)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
	}
	line_length = 0;
	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, INITIAL_BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				if (line_length == 0)
					return (-1);
				break;
			}
			buffer_index = 0;
		}
		if (buffer[buffer_index] == '\n')
		{
			buffer_index++;
			break;
		}
		if (line_length + 1 >= *n)
			return (-1);
		(*lineptr)[line_length++] = buffer[buffer_index++];
	}
	(*lineptr)[line_length] = '\0';
	return (line_length);
}


/**
  *_getenv - Get the value of an environment variable.
  *
  *@input: Name of the environment variable.
  *
  *Return: Value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *input)
{
	int index;
	int jdex;
	int stat;

	for (index = 0; environ[index] != NULL; index++)
	{
		stat = 1;
		for (jdex = 0; environ[index][jdex] != '=' && input[jdex] != '\0'; jdex++)
		{
			if (environ[index][jdex] != input[jdex])
			{
				stat = 0;
				break;
			}
		}

		if (environ[index][jdex] == '=' && stat)
		{
			return (&environ[index][jdex + 1]);
		}
	}
	return (NULL);
}
