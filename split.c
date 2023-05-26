#include "shell.h"

/**
 * count_word - function that calculate
 * number of words that were splitted
 * with del
 *
 * @line: to be splitted
 * @del: to be split with
 * Return: number of words
 */
int count_word(char *line, const char *del)
{
	int len;
	char *token;

	len = 0;
	token = strtok(line, del);
	while (token)
	{
		len++;
		token = strtok(NULL, del);
	}
	free(line);
	return (len);
}

/**
 * split - function that splits given string
 * into multiple substrings
 *
 * @line: line to be splitted
 * @del: to split with
 * Return:  2d array of characters with trailing
 * NULL
 */
char **split(char *line, const char *del)
{
	char **tokens, *token;
	int token_len, iterator;

	token_len = count_word(_strdup(line), del);
	tokens = malloc(sizeof(char *) * (token_len + 1));
	if (!tokens)
		return (NULL);
	token = strtok(line, del);
	iterator = 0;
	while (token != NULL)
	{
		tokens[iterator] = token;
		iterator++;
		token = strtok(NULL, del);
	}
	tokens[iterator] = NULL;
	return (tokens);
}
