#include "shell.h"

/**
 * get_command - This function gets the name of the command entered when the
 * user enters a direction path.
 * @str: It's a pointer to the direction path.
 *
 * Return: It returns a pointer to the name of the command.
 */
char *get_command(char *str)
{
	char *token, *lastToken = NULL;

	token = strtok(str, "/");

	while (token != NULL)
	{
		if (lastToken != NULL)
			free(lastToken);
		lastToken = strdup(token);
		if (lastToken == NULL)
			return (NULL);
		token = strtok(NULL, "/");
	}
	return (lastToken);
}
