#include <stdio.h>
#include <string.h>

/**
 * main - This program prints the list of tokens of a string entered by a
 * user.
 *
 * Return: Always 0;
 */
int main(void)
{
	char str[100];
	char *token;

	printf("Write a string: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

	/* Tokenize the input command */
	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
