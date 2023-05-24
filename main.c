#include "shell.h"

/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 upon successful execution
 */
int main(int ac, char **argv)
{
	(void)ac;
	(void)argv;
	char *lineptr = NULL, *lineptr_cp = NULL;
	size_t n = 0;
	int num_char = 0;
	const char *delim = " \n";

	while (1)
{
	write(1, "$ ", 2);
	num_char = getline(&lineptr, &n, stdin);
	if (num_char == EOF)
		perror("getline");
	lineptr[num_char - 1] = '\0';
	printf("%s\n", lineptr);

	free(lineptr);
}
	return (0);
}
