#include "shell.h"

/**
 * _getenv - This function gets an environment variable
 * (without using getenv).
 * @name: This is the name of the environment variable.
 *
 * Return: The value of the env variable or NULL if the name doesn't exist.
 */
char *_getenv(const char *name)
{
	char *ptr, *token, *value;
	int i = 0;

	if (name == NULL)
		return (NULL);
	while (environ[i] != NULL)
	{
		ptr = strdup(environ[i]);
		if (ptr == NULL)
			return (NULL);
		token = strtok(ptr, "=");
		if (token != NULL && strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");
			if (token == NULL || strcmp(token, "") == 0)
			{
				free(ptr);
				return (NULL);
			}
			value = strdup(token);
			free(ptr);
			if (value == NULL)
				return (NULL);
			return (value);
		}
		free(ptr);
		i++;
	}
	return (NULL);
}
