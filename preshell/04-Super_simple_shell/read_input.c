#include "shell.h"

/**
 * read_input - This function read a line from the standard input and saves
 * the command name in the str string.
 * @str: Is the string to save the command.
 * @size: Is the size of the string.
 *
 * Return: None.
 */
void read_input(char *str, size_t size)
{
	/*Check for errors or end-of-file*/
	if (fgets(str, size, stdin) == NULL)
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
	str[strcspn(str, "\n")] = '\0';
}
