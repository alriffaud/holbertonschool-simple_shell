#ifndef _SHELL_H_
#define _SHELL_H_

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Declare the external variable */
	extern char **environ;

/* Functions */
void show_prompt(void);
void read_input(char **str, size_t *size);
void run_command(char *str);
char *_getenv(const char *name);
char **str_token(char *str);
char **str_token_arg(char *str);
char **add_to_path(char **paths, char *name);
int search_program(char **paths);
int get_and_find(char *name);
char *get_command(char *str);

#endif
