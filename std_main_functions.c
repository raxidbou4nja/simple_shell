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