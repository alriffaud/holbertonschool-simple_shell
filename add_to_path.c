#include "shell.h"

/**
 * add_to_path - This function adds a command name to a given array of paths.
 * @paths: It's a pointer to the paths array.
 * @name: It's the name of the command to add.
 *
 * Return: A pointer to the new array of paths.
 */
char **add_to_path(char **paths, char *name)
{
	int i, j, path_count = 0, new_path_length;
	char **new_paths;

	if (paths == NULL || *paths == NULL || name == NULL)
		return (NULL);
	while (paths[path_count] != NULL)
		path_count++;
	new_paths = malloc(sizeof(char *) * (path_count + 1));
	if (new_paths == NULL)
		return (NULL);
	for (i = 0; i < path_count; i++)
	{
		new_path_length = strlen(paths[i]) + strlen(name) + 2;
		new_paths[i] = malloc(new_path_length);
		if (new_paths[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(new_paths[j]);
			free(*new_paths);
			return (NULL);
		}
		sprintf(new_paths[i], "%s/%s", paths[i], name);
	}
	new_paths[path_count] = NULL;
	return (new_paths);
}
