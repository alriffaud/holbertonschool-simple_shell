#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;


/**
 * _unsetenv - This function deletes an environment variable (without using
 * unsetenv).
 * @name: It's the name of the env variable.
 *
 * Return: 0 on success and -1 on failure.
 */
int _unsetenv(const char *name)
{
	char *ptr, *token;
	char *delimiter = "=";
	int i = 0;

	if (name == NULL)
		return (-1);
	while (environ[i] != NULL)
	{
		ptr = strdup(environ[i]);
		if (ptr == NULL)
			return (-1);
		token = strtok(ptr, delimiter);
		if (token != NULL && strcmp(name, token) == 0)
		{
			free(ptr);
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			return (0);
		}
		free(ptr);
		i++;
	}
	return (0);
}

/**
 * main - This program modified the environment array.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *name = "PATH";
	int i = 0;

	if (_unsetenv(name) == 0)
	{
		printf("Environment variable set successfully.\n");
	}
	else
	{
		perror("Error setting environment variable");
	}
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
