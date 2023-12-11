#include "shell.h"

/**
 * run_command - This function create a child process to ejecute the command
 * entered.
 * @args: Is a pointer to the list of arguments.
 *
 * Return: None.
 */
void run_command(char **args)
{
	char *env[] = {NULL};
	pid_t child_pid;
	char *name;
	char path[100];

	if (args == NULL || args[0] == NULL)
		return;
	name = get_command(args[0]);
	if (name == NULL)
		return;
	if (get_and_find(args[0]) == 1 || get_and_find(name) == 1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			free(name);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			snprintf(path, sizeof(path), "./%s", name);
			execve(path, args, env);
			snprintf(path, sizeof(path), "/bin/%s", name);
			execve(path, args, env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	else
		fprintf(stderr, "Error: Program not found\n"), free(name);
}
