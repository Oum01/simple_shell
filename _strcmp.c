#include "shell.h"
/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: An integer value indicating the comparison result.
 *	- If the two strings are equal, returns 0.
 *	- If the first string is greater, returns a positive value.
 *	- If the second string is greater, returns a negative value.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
