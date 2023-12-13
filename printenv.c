#include "shell.h"

/**
 * printenv - prints the enviroment using environ.
 *
 * Return: None.
 */
void printenv(void)
{
	char **env;

	env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
