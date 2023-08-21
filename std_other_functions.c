#include "libshell.h"

/**
 * _strdup - duplicates a string.
 * @src: source string to be duplicated.
 *
 * Return: pointer to allocate duplicated string.
 */
char *_strdup(const char *src)
{
	char *dup;
	size_t length = 0;
	size_t i = 0;

	if (src == NULL)
	{
		return (NULL);
	}

	while (src[length] != '\0')
	{
		length++;
	}

	dup = (char *)malloc(length + 1);

	if (dup == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i <= length; i++)
	{
		dup[i] = src[i];
	}

	return (dup);
}

/**
 * _strcpy - Copy a string.
 * @dest: dest buffer to copy into.
 * @src: source string to copy from.
 */
void _strcpy(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
	{
		return;
	}


	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}


	*dest = '\0';
}

/**
 * _strcat - append string to other
 * @dest: Destination string
 * @src: Source String
 * Return: Pointer to the next token
 */

char *_strcat(char *dest, const char *src)
{
	char *str = dest + _strlen(dest);

	while (*src != '\0')
	{
		*str = *src;
		str++;
		src++;
	}

	*str = '\0';
	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: first string to compare.
 * @s2: second string to compare.
 *
 * Return: 0 if similar 1 if not
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(const char *s)
{
	int sign = 1;
	int result = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return (result * sign);
}
