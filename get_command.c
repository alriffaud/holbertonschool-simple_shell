#include "shell.h"

/**
 * get_command - This function gets the name of the command entered when the
 * user enters a direction path.
 * @str: It's a pointer to the direction path.
 *
 * Return: It returns a pointer to the name of the command.
 */
char *get_command(char *str, char *only_path)
{
	char *token, *lastToken = NULL;

	token = strtok(str, "/");
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
			return (NULL);
		token = strtok(NULL, "/");
	}
	return (lastToken);
}

/*int main(void)
{
	char str[] = "/a/b/c/ls";
	char only_path[100];
	char *name;

	only_path[0] = '\0';
	name = get_command(str, only_path);
	printf("Name: %s\n", name);
	printf("only_path: %s\n", only_path);
	free(name);
	return (0);
}*/
