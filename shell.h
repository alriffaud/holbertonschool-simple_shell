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
#include <signal.h>
#include <limits.h>
#include <errno.h>

/* Declare the external variables */
	extern char **environ;

/* Functions */
void show_prompt(void);
void read_input(char **str, size_t *size);
void run_command(char **args, char *av);
char *_getenv(const char *name);
char **str_token(char *str);
char **str_token_arg(char *str);
char **add_to_path(char **paths, char *name);
int search_program(char **paths);
int get_and_find(char *name);
char *get_command(char *str, char *only_path);
void freeMemory(char **args);
void printenv(void);
void free_paths_value(char **paths, char *value);
void get_absolute_path(char *only_path, char *cwd);

#endif
