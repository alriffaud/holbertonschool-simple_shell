#include "shell.h"

/**
 * freeMemory - Function to free the memory of the args array.
 * @args: It's a pointer to the arguments array.
 *
 * Return: None.
 */
void freeMemory(char **args)
{
	int i;

	for (i = 0; args != NULL && args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
	args = NULL;
}
