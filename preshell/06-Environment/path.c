#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _getenv - This function gets an environment variable
 * (without using getenv).
 * @name: This is the name of the environment variable.
 * @env: Is a pointer to the environment variables array.
 *
 * Return: The value of the env variable or NULL if the name doesn't exist.
 */
char *_getenv(const char *name, char **env)
{
	char *ptr, *token, *value;
	char *delimiter = "=";
	int i = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		ptr = strdup(env[i]);
		if (ptr == NULL)
			return (NULL);
		token = strtok(ptr, delimiter);
		if (token != NULL && strcmp(name, token) == 0)
		{
			token = strtok(NULL, delimiter);
			value = strdup(token);
			if (value == NULL)
				return (NULL);
			free(ptr);
			return (value);
		}
		free(ptr);
		i++;
	}
	return (NULL);
}

/**
 * main - This program gets the PATH environment value and prints each
 * directory.
 * @ac: Is the number of arguments passed to the program.
 * @av: Is a one-dimensional array of arguments.
 * @env: Is a one-dimensional array of environment variables.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *value, *token;
	char *delimiter = ":";

	(void) ac;
	(void) av;
	value = _getenv("PATH", env);
	token = strtok(value, delimiter);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delimiter);
	}
	return (0);
}
