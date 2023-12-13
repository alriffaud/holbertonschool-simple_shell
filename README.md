<h1>Simple Shell</h1>
</div>

## Description

This Simple Shell project, is a basic shell implementation with the primary goal of providing a user-friendly interface for executing commands. The shell supports essential features, including prompt display, command execution, handling errors, and incorporating built-in commands. Special characters, cursor movement, and command arguments are also supported.

## Compilation

To compile the shell, use the following command:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell

## Files and functions

* *shell.h:*
	* Header file containing function prototypes and necessary library inclusions.
* *shell.c:*
	* Main program that executes the shell, prompting for commands and running them.
* *show_prompt.c:*
	* Displays the shell prompt.
* *read_input.c:*
	* Function to read a line from standard input and process the command.
* *str_token_arg.c:*
	* Tokenization functions to split a string into arguments.
* *run_command.c:*
	* Function to create a child process and execute the entered command.
* *get_command.c:*
  	* Function to get the name of the command entered.
* *get_and_find.c:*
	* Function to execute the _getenv.c, str_token.c, add_to_path.c and search_program.c. 
* *str_token.c:*
	* Tokenizes a string into arguments.
* *_getenv.c:*
	* Function to get an enviroment variable.
* *add_to_path.c:*
	* Function to add a command to the end of a path.
* *search_program.c:*
	* Function to search if the program exist in a given path.
* *freeMemory.c:*
	* Function to free the memory of the args array
* *free_paths_value.c:*
	* Function to free memory of the paths a value arrays
* *printenv.c:*
	* Prints enviroment array using environ.

## Flowchart
![flowchart_shell.png](https://github.com/alriffaud/holbertonschool-simple_shell/blob/edf3844bbd978d49525148b01175381169d7820b/flowchart_shell.png)

## Usage

To run the shell, execute the compiled binary:


./shell

After launching, the shell will display a prompt, allowing users to input commands.
Also, you can redirect the command to be executed in non-interactive mode by the Simple Shell:


echo "/bin/ls" | ./shell


