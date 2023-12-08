#ifndef _SHELL_H_
#define _SHELL_H_

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Functions */
void show_prompt(void);
void read_input(char *str, size_t size);
void run_command(char *str);

#endif
