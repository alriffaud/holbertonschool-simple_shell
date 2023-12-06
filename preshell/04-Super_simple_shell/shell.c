#include "shell.h"

/**
 * main - This program execute the shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[100];

	while(1)
	{
		show_prompt();
		read_input(command, sizeof(command));
		run_command(command);
	}
	return (0);
}
