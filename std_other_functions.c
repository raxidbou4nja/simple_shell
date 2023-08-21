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
