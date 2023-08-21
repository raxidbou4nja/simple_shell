#include "libshell.h"

/**
  *_putchar - writes the character c to stdout
  *@c: The character to print
 *
  *Return: On success 1.
  *On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *_putstr - Prints a string to standard output
  *@str: The string to be printed
 *
  *Return: number of characters
 */
int _putstr(const char *str)
{
	int count = 0;

	if (str == NULL)
	{
		return (-1);
	}


	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}


/**
  *_strlen - Calculate the length of a string
 *
  *@str: The string for which to calculate the length
 *
  *Return: The length of the string
 */
size_t _strlen(const char *str)
{
	size_t strlen = 0;

	while (*str != '\0')
	{
		strlen++;
		str++;
	}

	return (strlen);
}

/**
  *_strtok - Tokenize a string
  *@str: The string to be tokenized
  *@delim: The set of delimiter characters
  *Return: Pointer to the next token
  *or NULL if no more tokens are found
 */

char *_strtok(char *str, const char *delim)
{
	static char *token;
	int is_delimed = 0;
	int f_token = 0;
	char *token_start = NULL;

	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);

	while (*token != '\0')
	{
		const char *d;

		is_delimed = 0;
		for (d = delim; *d != '\0'; d++)
		{
			if (*token == *d)
			{
				is_delimed = 1;
				break;
			}
		}
		if (!is_delimed && !f_token)
		{
			token_start = token;
			f_token = 1;
		}
		if (is_delimed && f_token)
		{
			*token = '\0';
			token++;
			return (token_start);
		}

		token++;
	}
	if (f_token)
		return (token_start);
	return (NULL);
}
