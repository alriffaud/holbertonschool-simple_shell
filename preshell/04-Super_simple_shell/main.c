#include "shell.h"

/**
 * main - main function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str = NULL;
	size_t len = 0;
	char *name;

	printf("Write a string: ");
	getline(&str, &len, stdin);
	str[strcspn(str, "\n")] = '\0';
	name = get_command(str);
	if (name != NULL)
		printf("%s\n", name);
	if (get_and_find(name) == 1)
		printf("found\n");
	if (get_and_find(name) == 0)
		printf("not found\n");
	return (0);
}
