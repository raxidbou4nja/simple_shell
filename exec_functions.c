#include "libshell.h"


/**
 * find_executable - find the full path of an executable command
 *
 * @command: The name of the command to find
 *
 * Return: On success, returns a dynamically allocated string
 */

char *find_executable(const char *command)
{
	char *path = _getenv("PATH");
	char *path_copy;
	char *path_token;
	char *path_delimiter = ":";
	char *executable_path = NULL;

	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path);
	path_token = _strtok(path_copy, path_delimiter);

	while (path_token != NULL)
	{
		executable_path = (char *)malloc(_strlen(path_token) + _strlen(command) + 2);
		if (executable_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		_strcpy(executable_path, path_token);
		_strcat(executable_path, "/");
		_strcat(executable_path, command);

		if (access(executable_path, X_OK) == 0)
		{
			free(path_copy);
			return (executable_path);
		}

		free(executable_path);
		executable_path = NULL;
		path_token = _strtok(NULL, path_delimiter);
	}

	free(path_copy);
	return (NULL);
}

/**
 * execute_command - execute a command with specified path and arguments
 *
 * @command_path: full path of the command to execute
 * @tokens: an array of command and arguments
 *
 * Return: function does not return a value.
 */

void execute_command(const char *command_path, char *tokens[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(command_path, tokens, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}


/**
 * tokenize_command - tokenizes the input command line
 * @command_line: input command line string
 * @tokens: array to store tokens
 * Return: number of tokens
 */

int tokenize_command(char *command_line, char *tokens[])
{
	char *token;
	int token_count = 0;
	const char *delimiter = " \n";

	token = _strtok(command_line, delimiter);

	while (token != NULL)
	{
		char *token_copy = (char *)malloc(_strlen(token) + 1);

		if (token_copy == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(token_copy, token);
		tokens[token_count++] = token_copy;
		token = _strtok(NULL, delimiter);
	}

	tokens[token_count] = NULL;
	return (token_count);
}
