#include "shell.h"

/**
 * main - This program executes the shell.
 * @ac: Is the number of arguments passed to the program.
 * @av: Is a one-dimensional array of strings.
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	char *str = NULL;
	char **args = NULL;
	size_t size = 0;

	(void) ac;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			show_prompt();
		read_input(&str, &size);
		if (*str == '\0')
			continue;
		args = str_token_arg(str);
		if (args == NULL || args[0] == NULL)
		{
			freeMemory(args);
			continue;
		}
		if (strcmp(args[0], "exit") == 0 || strcmp(str, "exit") == 0)
		{
			free(str);
			if (args[1] == NULL)
				freeMemory(args), exit(EXIT_SUCCESS);
			else
			{
				freeMemory(args);
				return (2);
			}
		}
		if (strcmp(args[0], "env") == 0 || strcmp(str, "env") == 0)
		{
			printenv();
			freeMemory(args);
			continue;
		}
		run_command(args, av[0], str);
		freeMemory(args);
	}
	free(str);
	return (0);
}
