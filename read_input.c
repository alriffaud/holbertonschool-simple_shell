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
	ssize_t read;

	/*Check for errors or end-of-file*/
	read = getline(str, size, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			free(*str);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(*str);
			perror("Error reading line");
			exit(EXIT_FAILURE);
		}
	}
	/* Remove the new line */
	(*str)[strcspn(*str, "\n")] = '\0';
	/* Replace tabs with spaces */
	while (strcspn(*str, "\t") < strlen(*str))
		(*str)[strcspn(*str, "\t")] = ' ';
}
