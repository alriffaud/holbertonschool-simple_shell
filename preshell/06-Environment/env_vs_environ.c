#include <stdio.h>

/* Declare the external variable */
extern char **environ;

/**
 * main - This program prints the ethe address of env and environ.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	printf("The address of env is: %p\n", (void *)&env);
	printf("The address of environ is: %p\n", (void *)&environ);
	return (0);
}
