#include "shell.h"

/**
 * _strlen - Computes the length of a string
 * @str: The string to compute the length of
 *
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
