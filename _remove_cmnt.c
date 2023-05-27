#include "shell.h"

/**
 * remove_comments - function that removes
 * comments from line
 *
 * @s: string
 * Return: given string with comments removed
 */
char *remove_comments(char *s)
{
	int is_space, index;

	if (!s)
		return (NULL);
	is_space = 1;
	index = 0;
	while (s[index])
	{
	if (s[index] == ' ' || s[index] == '\t')
		is_space = 1;
	else if (s[index] == '#' && is_space)
	{
		s[index] = 0;
	break;
	}
	else
		is_space = 0;
	index++;
	}
	return (s);
}
