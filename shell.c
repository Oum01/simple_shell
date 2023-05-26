#include "shell.h"

/**
 * prompt - function that will showed
 * to the user to enter commands
 *
 * Return: (void)
 */
void prompt(void)
{
	if (isatty(0))
		write(1, "$> ", 3);
}

/**
 * handle_ctrl_c - function that will be
 * passed to the signal to handle
 * ctrl-c
 *
 * @sig: signint signal number
 * Return: (void)
 */
void handle_ctrl_c(int sig)
{
	(void)sig;

	if (isatty(0))
		write(1, "\n$> ", 4);
}

/**
 * main - entry point to the program
 *
 * @ac: number of arguments
 * @av: arguments
 * Return: (0) success, otherwise error
 */
int main(int ac, char *av[])
{
	char *line, **tokens;
	size_t len;

	(void)ac;
	_global_variables(SET_PROGRAM_NAME, av[0]);
	signal(SIGINT, handle_ctrl_c);
	while (1)
	{
		line = NULL;
		prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}
		tokens = split(line, " \t\n");
		if (!tokens || !*tokens)
		{
			free(line);
			free(tokens);
			continue;
		}
		_global_variables(INCREMENT_LINE, NULL);
		if (!_strcmp(tokens[0], "exit"))
		{
			free(line);
			free(tokens);
			__exit();
		}
		else if (!_strcmp(tokens[0], "env"))
			_env();
		else
			execute(tokens, line);
		free(line);
		free(tokens);
	}
	return (_status_code(GET_STATUS, 0));
}
