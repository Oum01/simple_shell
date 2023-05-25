#include "shell.h"

/**
 * _strdup - Duplicates a string
 * @str: The string to be duplicated
 *
 * Return: A pointer to the newly duplicated string
 */
char *_strdup(const char *str)
{
	int len, iterator;
	char *newstr;

	iterator = 0;
	len = _strlen(str);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	iterator = 0;
	while (str[iterator] != '\0')
	{
		newstr[iterator] = str[iterator];
		iterator++;
	}
	newstr[iterator] = '\0';
	return (newstr);
}
