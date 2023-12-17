#include "shell.h"

/**
 * get_and_find - This function executes the _getenv, str_token, add_to_path
 * and search_program functions.
 * @name: It's the name of the environment variable.
 *
 * Return: 1 if the program is found, 0 if it's not, and -1 if there are any
 * errors.
 */
int get_and_find(char *name)
{
	char *value, path[100];
	char **paths, **paths_name;
	int i, j = 0, res;

	if (name == NULL)
		return (-1);
	value = _getenv("PATH");
	if (strcmp(value, "") == 0)
	{
		free(value);
		return (-1);
	}
	paths = str_token(value);
	if (paths != NULL)
	{
		paths_name = add_to_path(paths, name);
		if (paths_name == NULL)
		{
			fprintf(stderr, "Error: Failed to add command to paths\n");
			for (i = 0; paths[i] != NULL; i++)
				free(paths[i]);
			free(paths), free(value);
			return (-1); }
		res = search_program(paths_name);
		while (paths_name[j] != NULL)
			free(paths_name[j]), j++;
		free(paths_name);
		for (i = 0; paths[i] != NULL; i++)
			free(paths[i]);
		free(paths), free(value);
	}
	if (name[0] >= 97 && name[0] <= 122)
	{
		sprintf(path, "./%s", name);
		if (access(path, F_OK) == 0)
			res = 1;
		sprintf(path, "/bin/%s", name);
		if (access(path, F_OK) == 0)
			res = 1; }
	return (res);
}
