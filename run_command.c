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
	char *env[] = {"PATH", NULL};
	pid_t child_pid;
	char *name;
	char path[100];

	if (args == NULL || args[0] == NULL)
		return;
	name = get_command(args[0]);
	if (name == NULL)
		return;
	if ((get_and_find(name) == 1 || get_and_find(args[0]) == 1))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			free(name);
			freeMemory(args);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			snprintf(path, sizeof(path), "./%s", name);
			execve(path, args, env);
			snprintf(path, sizeof(path), "/bin/%s", name);
			execve(path, args, env);
			perror("execve");
			freeMemory(args);
			free(name);
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
		free(name);
	}
	else
		fprintf(stderr, "%s: %s: not found\n", av, args[0]), free(name);
}
