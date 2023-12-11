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

</p>

## Completed projects
| Task # | Type | Short description |
| ---: | --- | --- |
|0 | *Mandatory*     | It handle the conversion specifiers: c, s and %. |
|1 | *Mandatory*     | Handle the following conversion specifiers: d i |
|2 | *Mandatory*     | Create a man page for your function.
|3 | Advanced        | Handle the following custom conversion. b: the unsigned int argument is converted to binary |
|4 | Advanced        | Handle the following conversion in: u, o, x, X |
|5 | Advanced        | Use a local buffer of 1024 chars in order to call write as little as possible. |
|6 | Advanced        | Handle the following conversion specifier: p. |
|7 | Advanced        | Handle the following custom conversion: S: print the string |
|8 | Advanced        | Handle the following flag characters for non-custom conversion specifiers: +, space, # |
|9 | Advanced        | Handle the following length modifiers for non-custom conversion specifiers: l, h. Conversion specifiers to handle: d, i, u, o, x, X |


## Usage

To run the shell, execute the compiled binary:


./hsh

After launching, the shell will display a prompt, allowing users to input commands.
Also, you can redirect the command to be executed in non-interactive mode by the Simple Shell:


echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2



## Parameters

| Function                        | conversion specifier                | Description                               |
| :------------------             | :------------------                 | :---------------------------------------- |
| print_char                    | c                                 | *print_char*.the function is used to display the character        |
| print_string                  | s                                 | *print_string*.the function is used to display the string        |
| _printf                        | d i                             | *print_int*.the int argument is converted to signed decimal notation. |
| _printf                      | %                                 | **%**. No argument is converted |
| print_oct                      | o                                 | *print_oct*. the function is used to print a number in octal|
| print_bin                      | b                                 | *print_bin* the function is used to print a number in binary|
| print_hex                      | x                                 | *print_hex*. the function is used to print a number in lowercase hexadecimal base|
| print_hex_upper                      | X                                 | *print_hex_upper*. the function is used to print a number in a uppercase hexadecimal base|
| print_uint                      | u                                 | *print_uint*. the function is used to print a unsigned integer|
| non_print_char                      | S \x                                | *non_print_char*. handles non-printable characters: \x, followed by the ASCII code value in uppercase hexadecimal.|
| print_addr                      | p                                 | *print_addr*. the function is used to print the address of a pointer |

## Authors

- Germán Silveira <a href="https://github.com/Daldanos" rel="nofollow"><img aling="center" alt="github" src="https://1000logos.net/wp-content/uploads/2021/05/GitHub-logo.png" height="24" /></a>
- Alberto Riffaud <a href="https://github.com/alriffaud" rel="nofollow"><img aling="center" alt="github" src="https://1000logos.net/wp-content/uploads/2021/05/GitHub-logo.png" height="24" /></a>
El readme, falta parameters y completed projects
