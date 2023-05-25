#include "shell.h"
/**
 * get_path - Retrieves the PATH environment variable value.
 *
 * Return: A pointer to a string containing the PATH value,
 *         or NULL if the PATH variable is not set.
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
 * get_command_path - Retrieves the full path of a command.
 * @command_name: The name of the command.
 *
 * Return: A pointer to a string containing the full path of the command,
 *         or NULL if the command is not found in the PATH.
 */
	char *get_command_path(char *command_name)
	{
		char *path, **path2d, **iterator, dest[200];
		struct stat st;

	if ((command_name[0] == '.' || command_name[0] == '/') &&
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
 * execute - Executes a command with the given tokens.
 * @tokens: An array of tokens representing the command and its arguments.
 */
	void execute(char **tokens)
	{
		char *command_with_path;
		int pid, status;

		command_with_path = get_command_path(tokens[0]);
		if (!command_with_path)
		{
			write(2, "Command Not Found\n", 19);
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
		free(tokens);
		perror("$");
		if (errno == EACCES)
			_exit(126);
		exit(errno);
		}
		else
		{
		wait(&status);
		_status_code(UPDATE_STATUS, WEXITSTATUS(status));
		free(command_with_path);
		}
	}
