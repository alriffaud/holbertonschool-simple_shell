#include "shell.h"

/**
 * run_command - This function creates a child process to execute the command
 * entered.
 * @args: It's a pointer to the list of arguments.
 * @av: Is a one-dimensional array of strings.
 * @str: Is a pointer to the string entered by the user.
 *
 * Return: None.
 */
void run_command(char **args, char *av, char *str)
{
	char *env[] = {NULL}, *value, *name, *cwd;
	char **paths;
	pid_t child_pid;
	char path[200], only_path[100];
	size_t i;

	if (args == NULL || args[0] == NULL)
		return;
	only_path[0] = '\0';
	name = get_command(args[0], only_path);
	if (name == NULL)
		return;
	if (get_and_find(name, args[0]) == 1)
	{
		value = _getenv("PATH");
		paths = str_token(value);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:"), free(name), freeMemory(args);
			exit(EXIT_FAILURE); }
		if (child_pid == 0)
		{
			sprintf(path, "./%s", name), execve(path, args, env);
			sprintf(path, "/bin/%s", name), execve(path, args, env);
			for (i = 0; paths != NULL && paths[i] != NULL && i < strlen(*paths); i++)
				sprintf(path, "%s/%s", paths[i], name), execve(path, args, env);
			cwd = malloc(PATH_MAX);
			get_absolute_path(only_path, cwd);
			sprintf(path, "%s/%s", only_path, name);
			execve(path, args, env), free(cwd);
			perror(path), freeMemory(args), free(name);
			free_paths_value(paths, value), exit(EXIT_FAILURE); }
		else
			wait(NULL);
		free_paths_value(paths, value), free(name); }
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", av, args[0]), free(name);
		freeMemory(args), free(str), exit(127); }
}
