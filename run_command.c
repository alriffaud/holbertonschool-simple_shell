#include "shell.h"

/**
 * run_command - This function creates a child process to execute the command
 * entered.
 * @str: It's a pointer to the list of arguments.
 *
 * Return: None.
 */
void run_command(char *str) /* **args */
{
	char *args[2];
	char *env[] = {NULL};
	pid_t child_pid;
	char *name;
	char path[100];
	char *token;

	token = strtok(str, " ");
	/*if (args == NULL || args[0] == NULL)*/
		/*return;*/
	name = get_command(token);/*args[0]*/
	if (name == NULL)
		return;
	if ((get_and_find(name) == 1 || get_and_find(token) == 1) /*args[0]*/
			&& strcmp(token, "ls") != 0)/*args[0]*/
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
			args[0] = malloc(strlen(token) + 1);
			if (args[0] == NULL)
				exit(EXIT_FAILURE);
			strcpy(args[0], token);
			args[1] = NULL;
			snprintf(path, sizeof(path), "./%s", name);
			execve(path, args, env);
			snprintf(path, sizeof(path), "/bin/%s", name);
			execve(path, args, env);
			perror("execve");/*args[0]*/
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	else
		fprintf(stderr, "./shell: No such file or directory\n"), free(name);
}
