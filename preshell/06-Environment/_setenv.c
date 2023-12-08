#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;


/**
 * _setenv - This function changes or adds an environment variable (without
 * using setenv).
 * @name: It's the name of the env variable.
 * @value: It's the value of the env variable.
 * @overwrite: It's an integer number to indicate if the value needs to be
 * overwritten.
 *
 * Return: 0 on success and -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *ptr, *token, *nameValue;
	char *delimiter = "=";
	int i = 0;

	if (name == NULL || value == NULL)
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
			if (overwrite == 0)
				return (0);
			nameValue = malloc(strlen(name) + strlen(value) + 2);
			if (nameValue == NULL)
				return (-1);
			/* Create the new "name=value" string */
			snprintf(nameValue, strlen(name) + strlen(value) + 2,
					"%s=%s", name, value);
			environ[i] = nameValue;
			return (0);
		}
		free(ptr);
		i++;
	}
	nameValue = malloc(strlen(name) + strlen(value) + 2);
	if (nameValue == NULL)
		return (-1);
	/* Create the new "name=value" string */
	snprintf(nameValue, strlen(name) + strlen(value) + 2, "%s=%s", name,
			value);
	environ[i] = nameValue;
	environ[i + 1] = NULL;
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
	const char *value = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/root";
	int i = 0;

	if (_setenv(name, value, 1) == 0)
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
