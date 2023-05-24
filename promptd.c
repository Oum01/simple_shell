#include "main.h"

/**
 * main - Entry point for the simple UNIX command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];
	char *token;
	int status;

	while (1)
	{
		printf("shell> ");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("Error reading command\n");
			continue;
		}

		command[strcspn(command, "\n")] = '\0';

		int arg_count = 0;
		token = strtok(command, " ");
		while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
		{
			arguments[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		arguments[arg_count] = NULL;

		pid_t pid = fork();
		if (pid < 0)
		{
			printf("Fork failed\n");
			continue;
		}
		else if (pid == 0)
		{
			execvp(arguments[0], arguments);
			printf("Command not found\n");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
