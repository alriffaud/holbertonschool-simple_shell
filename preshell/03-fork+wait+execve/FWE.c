#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - This program executes the command ls -l /tmp in 5 different child
 * processes.
 *
 * Descripion: Each child is created by the same process (the father). It's
 * wait for a child to exit before creating a new child.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *env[] = {NULL};
	pid_t child_pid, my_pid, father_pid;
	int status, i;

	my_pid = getpid();
	printf("\nThe current PID is: %u\n\n", my_pid);
	for (i = 0; i < 5; i++)
	{
		printf("-------------------------------------------------");
		printf("-----------\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			father_pid = getppid();
			printf("My father PPID is: %u\n", father_pid);
			my_pid = getpid();
			printf("The current child PID is: %u\n", my_pid);
			execve("/bin/ls", args, env);
		}
		else
		{
			wait(&status);
			printf("The number %d child has finished.\n", i + 1);
		}
	}
	printf("\n");
	return (0);
}
