#include "shell.h"

/**
 * run_command - This function creates a child process to execute the command
 * entered.
 * @args: It's a pointer to the list of arguments.
 * @av: Is a one-dimensional array of strings.
 *
 * Return: None.
 */
void run_command(char **args, char *av)
{
	char *env[] = {NULL}, *value, *name, *cwd;
	char **paths;
	pid_t child_pid;
	char path[100], only_path[100];
	size_t i;

	if (args == NULL || args[0] == NULL)
		return;
	only_path[0] = '\0';
	name = get_command(args[0], only_path);
	if (name == NULL)
		return;
	if ((get_and_find(name) == 1 || get_and_find(args[0]) == 1))
	{
		value = _getenv("PATH");
		/*if (value == NULL)
		{
			fprintf(stderr, "Error: Failed to get PATH\n"), free(value);
			return; }*/
		paths = str_token(value);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:"), free(name), freeMemory(args);
			exit(EXIT_FAILURE); }
		if (child_pid == 0)
		{
			sprintf(path, "./%s", name);
			execve(path, args, env);
			/*execve(args[0], args, env);*/
			for (i = 0; paths[i] != NULL && i < strlen(*paths); i++)
			{
				sprintf(path, "%s/%s", paths[i], name);
				execve(path, args, env); }
			cwd = malloc(PATH_MAX);
			get_absolute_path(only_path, cwd);
			sprintf(path, "%s/%s", cwd , name);
			execve(path, args, env);
			free(cwd);
			perror(args[0]), freeMemory(args), free(name);
			free_paths_value(paths, value);
			exit(EXIT_FAILURE); }
		else
			wait(NULL);
		free_paths_value(paths, value), free(name); }
	else
		fprintf(stderr, "%s: %s: not found\n", av, args[0]), free(name);
}
