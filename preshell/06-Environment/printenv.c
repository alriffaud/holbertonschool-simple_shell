#include <stdio.h>

/* Declare the external variable */
extern char **environ;

/**
 * main - prints the enviroment using environ.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **env;

	env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
