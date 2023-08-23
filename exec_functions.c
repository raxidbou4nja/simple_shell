#include "libshell.h"

/**
 * find_executable - find full path of an executable command
 *
 * @command: command's name to find
 *
 * Return: if success, returns a dynamically allocated string
 */

char *find_executable(char *command)
{
	static char executable_path[256];
	char *path = _getenv("PATH");
	char *cpath = _strdup(path);
	char *tpath = _strtok(cpath, ":");

	if (access(command, X_OK) == 0)
	{
		free(cpath);
		return (command);
	}

	while (tpath != NULL)
	{
		_strcpy(executable_path, tpath);
		_strcat(executable_path, "/");
		_strcat(executable_path, command);

		if (access(executable_path, X_OK) == 0)
		{
			free(cpath);
			return (executable_path);
		}

		tpath = _strtok(NULL, ":");
	}

	free(cpath);
	return (NULL);
}


/**
 * command_executioner - execute a command with specified path and arguments
 *
 * @exec_file_name: execution file name
 * @argv: array of command and arguments
 * @errori: errors counter index
 *
 */

void command_executioner(char *exec_file_name, char **argv, int errori)
{
	char *prompt = NULL, *actCommand = NULL;

		prompt = argv[0];

		actCommand = find_executable(prompt);

	if (actCommand != NULL)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execve(actCommand, argv, NULL);
			free(actCommand);
			perror("execve");
			/*exit(EXIT_FAILURE);*/
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		char error_code_str[16];

		snprintf(error_code_str, sizeof(error_code_str), "%d", errori);
		write(STDOUT_FILENO, exec_file_name, strlen(exec_file_name));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, error_code_str, strlen(error_code_str));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, argv[0], strlen(argv[0]));
		write(STDOUT_FILENO, ": not found\n", 12);
	}
}


/**
 * toknizer - tokenize a string into commands
 * @command_line: input string to tokenize
 * @tokens: array to store the resulting commands
 *
 * Return: The number of commands found
 */

int toknizer(char *command_line, char *tokens[])
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
