#include "shell.h"

/**
 * read_input - This function reads a line from the standard input and saves
 * the command name in the str string.
 * @str: It's the string to save the command.
 * @size: It's the size of the string.
 *
 * Return: None.
 */
void read_input(char **str, size_t *size)
{
	/*Check for errors or end-of-file*/
	if (getline(str, size, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error reading line");
			exit(EXIT_FAILURE);
		}
	}
	/* Remove the new line */
	(*str)[strcspn(*str, "\n")] = '\0';
	/* Replace tabs with spaces */
	while (strcspn(*str, "\t") < strlen(*str))
		(*str)[strcspn(*str, "\t")] = ' ';
	/* Skip leading spaces */
	while (*str != NULL && **str != '\0' && **str == ' ')
		(*str)++;
	/*
	 * if (strcmp(*str, "exit") == 0)
	 * {
	 *	exit(EXIT_SUCCESS);
	 * }
	*/
}
