#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * add_node_end - This function adds a new node at the end of a list_t list.
 * @head: It's a pointer to the first element of the list.
 * @str: It's a pointer to the string element of the new node.
 *
 * Return: None.
 */
void add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *current = *head;

	if (new_node == NULL)
		return;

	if (str != NULL)
	{
		new_node->str = strdup(str);
		if (new_node->str == NULL)
		{
			free(new_node);
			return;
		}
		new_node->next = NULL;
		if (*head == NULL)
			*head = new_node;
		else
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
	}
}

/**
 * print_list - This function prints all the elements of a list_t list.
 * @h: It's a pointer to the first element of the list.
 *
 * Return: None.
 */
void print_list(const list_t *h)
{
	if (h == NULL)
		return;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->str);
		h = h->next;
	}
}

/**
 * free_list - This function frees a list_t list.
 * @head: It's a pointer to the first element of the list.
 *
 * Return: None.
 */
void free_list(list_t *head)
{
	list_t *current = head;
	list_t *next;

	while (current != NULL)
	{
		next = current->next;
		if (current->str != NULL)
		{
			free(current->str);
			current->str = NULL;
		}
		free(current);
		current = next;
	}
}

/**
 * _getenv - This function gets an environment variable
 * (without using getenv).
 * @name: This is the name of the environment variable.
 * @env: Is a pointer to the environment variables array.
 *
 * Return: The value of the env variable or NULL if the name doesn't exist.
 */
char *_getenv(const char *name, char **env)
{
	char *ptr, *token, *value;
	char *delimiter = "=";
	int i = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		ptr = strdup(env[i]);
		if (ptr == NULL)
			return (NULL);
		token = strtok(ptr, delimiter);
		if (token != NULL && strcmp(name, token) == 0)
		{
			token = strtok(NULL, delimiter);
			value = strdup(token);
			if (value == NULL)
				return (NULL);
			free(ptr);
			return (value);
		}
		free(ptr);
		i++;
	}
	return (NULL);
}

/**
 * main - This program gets the PATH environment value and prints each
 * directory.
 * @ac: Is the number of arguments passed to the program.
 * @av: Is a one-dimensional array of arguments.
 * @env: Is a one-dimensional array of environment variables.
 *
 * Return: If there are any errors return 0, otherwise 1.
 */
int main(int ac, char **av, char **env)
{
	list_t *head = NULL;
	char *value, *token;
	char *delimiter = ":";

	(void) ac;
	(void) av;
	value = _getenv("PATH", env);
	if (value == NULL)
	{
		fprintf(stderr, "Error: PATH env variable not found.\n");
		return (1);
	}
	token = strtok(value, delimiter);
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, delimiter);
	}
	print_list(head);
	free_list(head);
	free(value);
	return (0);
}
