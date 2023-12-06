#include <stdio.h>
#include <unistd.h>

/**
 * main - This program returns the PID of the current process.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}
