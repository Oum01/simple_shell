#include "shell.h"

/**
 * get_path - function that looks for
 * path in the valid path
 *
 * Return: void
 */
char *get_path(void)
{
	char *path, *line;
	char **envs, **chunks;

	envs = __environ;
	while (*envs)
	{
		line = _strdup(*envs);
		chunks = split(line, "=");
		if (!_strcmp(chunks[0], "PATH"))
		{
			path = _strdup(chunks[1]);
			free(line);
			free(chunks);
			return (path);
		}
		free(line);
		free(chunks);
		envs++;
	}
	return (NULL);
}

/**
 * get_command_path - function that get
 * command concatenated with the path
 *
 * @command_name: command name
 * Return: command
 */
char *get_command_path(char *command_name)
{
	char *path, **path2d, **iterator, dest[200];
	struct stat st;

	if ((command_name[0] == '.' ||
		 command_name[0] == '/') &&
		!stat(command_name, &st))
	{
		return (_strdup(command_name));
	}
	path = get_path();
	if (!path)
		return (NULL);
	path2d = iterator = split(path, ":");
	while (*iterator)
	{
		dest[0] = 0;
		_strcat(_strcat(_strcat(dest, *iterator), "/"), command_name);
		if (!stat(dest, &st))
		{
			free(path);
			free(path2d);
			return (_strdup(dest));
		}
		iterator++;
	}
	free(path);
	free(path2d);
	return (NULL);
}

/**
 * _print_error - function that prints errors
 *
 * @command: name of the command
 * @error_type: type of error
 * Return: (void)
 */
void _print_error(const char *command, const char *error_type)
{
	_fprintf(2, "%s: %d: %s: %s\n",
			 (char *)_global_variables(GET_PROGRAM_NAME, NULL),
			 *((int *)_global_variables(GET_LINE_NUMBER, NULL)),
			 command, error_type);
}

/**
 * execute - function that executes
 * given command
 *
 * @tokens: 2d array contain command
 * information
 * @line: string to be freed on child proccess
 * Return: (void)
 */
void execute(char **tokens, char *line)
{
	char *command_with_path;
	int pid, status;

	command_with_path = get_command_path(tokens[0]);
	if (!command_with_path)
	{
		_print_error(tokens[0], "not found");
		_status_code(UPDATE_STATUS, 127);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("$");
		_status_code(UPDATE_STATUS, 1);
		return;
	}
	else if (pid == 0)
	{
		execve(command_with_path, tokens, __environ);
		free(command_with_path);
		if (errno == EACCES)
		{
			_print_error(tokens[0], "Permission denied");
			free(line);
			free(tokens);
			_exit(126);
		}
		free(line);
		free(tokens);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		_status_code(UPDATE_STATUS, WEXITSTATUS(status));
		free(command_with_path);
	}
}
