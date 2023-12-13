<h1>Simple Shell</h1>
</div>

## Description

This Simple Shell project, is a basic shell implementation with the primary goal of providing a user-friendly interface for executing commands. The shell supports essential features, including prompt display, command execution, handling errors, and incorporating built-in commands. Special characters, cursor movement, and command arguments are also supported.

## Compilation

To compile the shell, use the following command:

bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Files and functions

* *shell.c:*
	* Main program that executes the shell, prompting for commands and running them.
* *str_token_arg.c:*
	* Tokenization functions to split a string into arguments.
* *run_command.c:*
	* Function to create a child process and execute the entered command.
* *read_input.c:*
	* Function to read a line from standard input and process the command.
* *shell.h:*
	* Header file containing function prototypes and necessary library inclusions.
* *show_prompt:*
	* Displays the shell prompt.
* *read_input:*
	* Reads a line from standard input and processes the command.
* *run_command:*
	* Creates a child process to execute the entered command.
* *str_token_arg:*
	* Tokenizes a string into arguments.
* *len_str_arg:*
	* Returns the number of words in a string.

## Flowchart
<p>
	[flowchart_shell.png](https://github.com/alriffaud/holbertonschool-simple_shell/blob/edf3844bbd978d49525148b01175381169d7820b/flowchart_shell.png)
</p>

## Usage

To run the shell, execute the compiled binary:


./hsh

After launching, the shell will display a prompt, allowing users to input commands.
Also, you can redirect the command to be executed in non-interactive mode by the Simple Shell:


echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2


## Authors

- Germán Silveira <a href="https://github.com/Daldanos" rel="nofollow"><img aling="center" alt="github" src="https://1000logos.net/wp-content/uploads/2021/05/GitHub-logo.png" height="24" /></a>
- Alberto Riffaud <a href="https://github.com/alriffaud" rel="nofollow"><img aling="center" alt="github" src="https://1000logos.net/wp-content/uploads/2021/05/GitHub-logo.png" height="24" /></a>
El readme, falta parameters y completed projects
