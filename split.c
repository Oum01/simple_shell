#include "shell.h"

/**
 * count_word - Counts the number of words in a string
 * @line: The string to count words from
 * @del: The delimiter used to split the string into words
 *
 * Return: The number of words in the string
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
 * split - Splits a string into an array of tokens
 * @line: The string to be split
 * @del: The delimiter used to split the string
 *
 * Return: An array of tokens
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
