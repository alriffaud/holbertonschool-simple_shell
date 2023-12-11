#include "shell.h"

/**
 * show_prompt - This function displays the prompt.
 *
 * Return: None.
 */
void show_prompt(void)
{
	if (isatty(STDOUT_FILENO))
	{
		printf("#cisfun$ ");
		fflush(stdout);
	}
}
