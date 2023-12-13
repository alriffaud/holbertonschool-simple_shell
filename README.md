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
[![](https://mermaid.ink/img/pako:eNptUtlugkAU_ZXJPGmiBpVFeGhT96WNppg0KfgwgauSMjMEhrry7x22xDblaTj3LHdO5oY97gO28D7kJ-9IYoG2Y5ch-b00HDugUQjIPkIYlqAtJGXXRO32090-8hPaxJxG4o6GzgcJBNrzGJXMBYtSsSvPQ8TbbY4Cv9dovK7Xm2azxqUPGt0WCRJHKCWIsHIIZ-nncUoJ85-zEhtJAWK8kI2dLf8CFlwhF1fzkr57YF8gKejThjPJHYvL7KoFxsVoli8gR6Ra3b4kAqhHwrDOnT3kLnJ2EY0CVik2L9v5c4YeyHXsXKaClwpI_npXS84LWuB3f1ezeEhcOZM4lsW-QZKQA1TCVSXs_yOs05fOdP2-kpX6sk7wvivpspbiFqYQUxL48gnc8qGLZZkUXGzJow97kobCxS7LJJWkgtsX5mFLxCm0cBr5RMA4IIeYUGztSZhINCLsk3Nak-Qvtm74jK2u2e_omqloA7Xb08yuYrTwJYc7hm4oal9TdW3Q042sha-FgdIZ6Iahqqai6rrZ100j-wHbEMZK?type=png)](https://mermaid.live/edit#pako:eNptUtlugkAU_ZXJPGmiBpVFeGhT96WNppg0KfgwgauSMjMEhrry7x22xDblaTj3LHdO5oY97gO28D7kJ-9IYoG2Y5ch-b00HDugUQjIPkIYlqAtJGXXRO32090-8hPaxJxG4o6GzgcJBNrzGJXMBYtSsSvPQ8TbbY4Cv9dovK7Xm2azxqUPGt0WCRJHKCWIsHIIZ-nncUoJ85-zEhtJAWK8kI2dLf8CFlwhF1fzkr57YF8gKejThjPJHYvL7KoFxsVoli8gR6Ra3b4kAqhHwrDOnT3kLnJ2EY0CVik2L9v5c4YeyHXsXKaClwpI_npXS84LWuB3f1ezeEhcOZM4lsW-QZKQA1TCVSXs_yOs05fOdP2-kpX6sk7wvivpspbiFqYQUxL48gnc8qGLZZkUXGzJow97kobCxS7LJJWkgtsX5mFLxCm0cBr5RMA4IIeYUGztSZhINCLsk3Nak-Qvtm74jK2u2e_omqloA7Xb08yuYrTwJYc7hm4oal9TdW3Q042sha-FgdIZ6Iahqqai6rrZ100j-wHbEMZK)
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
