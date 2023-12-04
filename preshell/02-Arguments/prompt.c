#include <stdio.h>
#include <stdlib.h>


int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");

	/* Read a line from the standard input (stdin) */
	read = getline(&line, &len, stdin);

	/*Check for errors or end-of-file*/
	if (read == -1)
	{
		perror("Error reading line");
		return (1);
	}

	/* Display the entered line */
	printf("%s", line);

	/* Free the allocated memory for the line */
	free(line);

	return (0);
}
