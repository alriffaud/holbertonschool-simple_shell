#include "shell.h"

/**
 * len_str_arg - This function returns the number of words in a string.
 * @str: It's the pointer to the string.
 *
 * Return: An integer representing the number of words or NULL if there is
 * any error.
 */
int len_str_arg(char *str)
{
	int count = 1, i = 0, len;

	len = strlen(str);
	if (str == NULL || len == 0)
	{
		return (0);
	}

	while (i < len)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * str_token_arg - This function returns an array of each word of the string.
 * @str: Is the string to split.
 *
 * Return: The string to split. NULL if there is any error.
 */
char **str_token_arg(char *str)
{
	char **new;
	char *token;
	int i = 0, j, n, len;

	len = strlen(str);
	if (str == NULL || len == 0)
		return (NULL);
	/* Skip leading spaces */
	while (*str != '\0' && *str == ' ')
		str++;
	n = len_str_arg(str);
	new = malloc(sizeof(char *) * (n + 1));
	if (new == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		len = strlen(token);
		new[i] = malloc(len + 1);
		if (new[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(new[j]);
				/*Free memory from previously duplicated items*/
			}
			free(new);
			return (NULL);
		}
		strcpy(new[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	new[i] = NULL;
	return (new);
}
