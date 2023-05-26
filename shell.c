#include "shell.h"

/**
 * prompt - Displays the prompt "$> " if input is from a terminal
 */
void prompt(void)
{
	if (isatty(0))
		write(1, "$> ", 3);
}

/**
 * handle_ctrl_c - Handles the SIGINT signal by displaying a new prompt
 * @sig: The signal number (unused)
 */
void handle_ctrl_c(int sig)
{
	(void)sig;

	if (isatty(0))
		write(1, "\n$> ", 4);
}

/**
 * main - Entry point of the program
 *
 * Return: The exit status of the program
 */
int main(void)
{
	char *line, **tokens;
	size_t len;

	signal(SIGINT, handle_ctrl_c);
	while (1)
	{
		line = NULL;
		prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			break;
		}
		tokens = split(line, " \t\n");
		if (!tokens || !*tokens)
		{
			free(line);
			continue;
		}
		if (!_strcmp(tokens[0], "exit"))
		{
			free(line);
			free(tokens);
			__exit();
		}
		else if (!_strcmp(tokens[0], "env"))
			_env();
		else
			execute(tokens);
		free(line);
		free(tokens);
	}
	return (_status_code(GET_STATUS, 0));
}
