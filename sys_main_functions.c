#include "libshell.h"




/**
	* _getenv - Get the value of an environment variable.
	*
	* @input: Name of the environment variable.
	*
	* Return: Value of the environment variable, or NULL if not found.
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

/**
 * _setenv - to update and change environment var
 *
 * @name: name of the environment variable.
 * @value: value to set.
 * @oWrite: indicating whether to overwrite
 *
 * Return: 0 on success, -1 if the maximum number of variables
 */
int _setenv(const char *name, const char *value, int oWrite)
{
	char env_vars[100][50];
	char env_vals[100][100];
	int env_count = 0;
	int i;

	for (i = 0; i < env_count; i++)
	{
		if (_strcmp(env_vars[i], name) == 0)
		{
			if (!oWrite)
				return (0);
			_strncpy(env_vals[i], value, 100 - 1);
			return (0);
		}
	}

	if (env_count < 100)
	{
		_strncpy(env_vars[env_count], name, 50 - 1);
		_strncpy(env_vals[env_count], value, 100 - 1);
		env_count++;
		return (0);
	}
	else
	{
		return (-1);
	}
}
