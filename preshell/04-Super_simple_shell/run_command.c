#include "shell.h"

/**
 * run_command - This function create a child process to ejecute the command
 * entered.
 * @str: Is a pointer tho the command string.
 * @size: Is the size of the string.
 *
 * Return: None.
 */
void run_command(char *str)
{
	char *args[2];
	char *env[] = {NULL};
	char path[100];
	pid_t child_pid;
	char *token;

	token = strtok(str, " ");
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0 && token != NULL)
	{
		args[0] = malloc(strlen(token) + 1);
		if (args[0] == NULL)
			exit(EXIT_FAILURE);
		strcpy(args[0], token);
		args[1]= NULL;
		/* Attempt to execute with "./%s" */
		snprintf(path, sizeof(path), "./%s", token);
		execve(path, args, env);
		/* If execve with "./%s" fails, try "/%s*/
		snprintf(path, sizeof(path), "/%s", token);
		execve(path, args, env);
		/* If both execve calls fail, free the allocated memory */
		free(args[0]);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
