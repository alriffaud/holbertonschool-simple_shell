#include "shell.h"

/**
 * get_absolute_path - This function returns the absolute path from the first
 * argument entered by the user.
 * @only_path: It's a pointer to the path entered by the user.
 *
 * Return: The absolute path.
 */
void get_absolute_path(char *only_path, char *cwd)
{
	int ch;

	ch = chdir(only_path);
	if(ch<0)
		printf("chdir change of directory not successful.\n");
	else
	{
		if (getcwd(cwd, PATH_MAX) == NULL)
			perror("getcwd() error");
	}
}

/*int main(void)
{
	char only_path[] = "/bin";
	char *cwd;
       
	cwd = malloc(PATH_MAX);
	get_absolute_path(only_path, cwd);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}*/
