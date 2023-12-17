#include "shell.h"

/**
 * get_command - This function gets the name of the command entered when the
 * user enters a direction path.
 * @str: It's a pointer to the direction path.
 * @only_path: It's a variable with only the path (without the command).
 *
 * Return: It returns a pointer to the name of the command.
 */
char *get_command(char *str, char *only_path)
{
	char *token, *lastToken = NULL, *tmp;

	tmp = strdup(str);
	if (tmp == NULL)
		return (NULL);
	token = strtok(tmp, "/");
	while (token != NULL)
	{
		if (lastToken != NULL)
		{
			strcat(only_path, "/");
			strcat(only_path, lastToken);
			free(lastToken);
			lastToken = NULL;
		}
		lastToken = strdup(token);
		if (lastToken == NULL)
		{
			free(tmp);
			return (NULL);
		}
		token = strtok(NULL, "/");
	}
	free(tmp);
	return (lastToken);
}
