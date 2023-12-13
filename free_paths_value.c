#include "shell.h"
/**
 * free_paths_value - Function to free memory of the paths and value variables.
 * @paths: It's a pointer to the array of the paths.
 * @value: It's a pointer to the array to the value of PATH env variable.
 *
 * Return: None.
 */
void free_paths_value(char **paths, char *value)
{
	int i;

	for (i = 0; paths[i] != NULL; i++)
		free(paths[i]);
	free(paths);
	free(value);
}
