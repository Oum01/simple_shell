#include "shell.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len1, iter;

	len1 = _strlen(dest);
	iter = 0;

	while (src[iter])
	{
		dest[len1 + iter] = src[iter];
		iter++;
	}
	dest[len1 + iter] = 0;
	return (dest);
}
