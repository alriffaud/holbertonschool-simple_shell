#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Declare the external variable */
	extern char **environ;


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
		/*if (token != NULL)
			printf("%s || %ld\n", token, strlen(token));*/
		if (token != NULL && strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");
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
 * main - This program gets an environment variable and prints it.
 *
 * Return: Always 0.
 */
int main(void)
{
	char name[100];
	char *value;

	printf("Write the name of the environment variable: ");
	scanf("%s", name);
	/*printf("%s || %ld\n", name, strlen(name));*/
	value = _getenv(name);
	if (value != NULL)
		printf("The value of the %s env variable is: %s\n", name, value);
	else
		printf("The %s env variable was not found.\n", name);
	return (0);
}
