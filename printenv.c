#include "shell.h"

/**
 * printenv - This function prints the enviroment array using environ.
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
