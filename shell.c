#include "shell.h"

/**
 * main - This program executes the shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str = NULL;
	char **args = NULL;
	size_t size = 0;
	int i;

	while (1)
	{
		show_prompt();
		read_input(&str, &size);
		args = str_token_arg(str);
		/*if (strcmp(args[0], "exit") == 0)
		{
			for (i = 0; args != NULL && args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
			args = NULL;
			free(str);
			exit(EXIT_SUCCESS);
		}*/
		run_command(args);
		/* Free memory allocated for arguments */
		for (i = 0; args != NULL && args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		args = NULL;
	}
	free(str);
	return (0);
}
