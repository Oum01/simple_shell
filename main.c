#include "shell.h"

/**
 * shell_prompt - Prints the shell prompt
 */
void shell_prompt(void)
{
	write(1, "$ ", 2);
}

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid = fork();
	int status;
	char *argv[] = {command, NULL};
	char *envp[] = {NULL};

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	exit(EXIT_SUCCESS);
}

/**
 * shell_loop - Runs the main loop of the shell
 */
void shell_loop(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *lineptr = NULL;
	size_t n = 0;
	int num_char = 0;

	while (1)
	{
		write(1, "$ ", 2);
		num_char = getline(&lineptr, &n, stdin);
		if (num_char == EOF)
			perror("getline");
		lineptr[num_char - 1] = '\0';
		write(1, lineptr, num_char - 1);
		write(1, "\n", 1);
		free(lineptr);
	}
	execute_command(command);
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	printf("Simple Shell\n");
	shell_loop();
	printf("\nExiting the shell.\n");
	return (0);
}
