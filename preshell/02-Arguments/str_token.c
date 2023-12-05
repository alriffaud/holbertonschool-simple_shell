#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * len_str - This function returns the number of word in a string.
 * @str: Is the pointer to the string.
 *
 * Return: An integer representing the number of word or NULL if there is
 * any error.
 */
int len_str(char *str)
{
	int count = 1, i = 0;

	if (str == NULL || strlen(str) == 0)
	{
        	return 0;
	}

	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i+1] != ' ')
		{
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * string_words - This function returns an array of each word of the string.
 * @str: Is the string to splitv.
 * @n: Is the number of token in the string.
 *
 * Return: The string to split. NULL if there any error.
 */
char **string_words(char *str, int n)
{
	char **new;
	char *token;
	int i = 0, j;

	if (str == NULL || strlen(str) == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (n + 1));
	if (new == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		new[i] = strdup(token);
		if (new[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(new[j]);
				/* Libera memoria de elementos duplicados antes */
			}
			free(new);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	new[i] = NULL;
	return (new);
}

/* print_array - This function prints an array.
 * @a: It a pointer to the array.
 *
 * Return: None.
 */
void print_array(char **a)
{
	int i = 0;
	
	if (a != NULL)
	{	
		while (a[i] != NULL)
		{
			printf("%s\n", a[i]);
			i++;
		}
	}
}

/** 
 * main - This program prints the list of words of a string entered by a user.
 *
 * Return: Always 0;
 */
int main(void)
{
	char str[100];
	int len, i;
	char **arr;

	printf("Write a string: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	len = len_str(str);
	arr = string_words(str, len);
	print_array(arr);
	/* Free allocated memory */
	for (i = 0; i < len; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return (0);
}
