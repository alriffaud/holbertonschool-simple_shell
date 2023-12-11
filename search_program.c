#include "shell.h"

/**
 * search_program - This function searches if a program exists in a given path.
 * @paths: It's the list of paths to search in.
 *
 * Return: 1 if the file exists, otherwise returns 0.
 */
int search_program(char **paths)
{
	int i = 0;

	while (paths[i] != NULL)
	{
		if (access(paths[i], F_OK) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
