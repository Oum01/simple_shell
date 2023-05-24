#include "main.h"

/**
 * main - Entry point for the UNIX command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command = NULL;
    size_t command_length = 0;
    int stdout_fd = STDOUT_FILENO;

    while (1)
    {
        write(stdout_fd, "shell> ", 7);

        if (getline(&command, &command_length, stdin) == -1)
        {
            perror("Error reading command");
            continue;
        }

        command[strcspn(command, "\n")] = '\0';

        char *arguments[MAX_ARGUMENTS];
        char *token;
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
            perror("Fork failed");
            continue;
        }
        else if (pid == 0)
        {
            if (execve(arguments[0], arguments, NULL) == -1)
            {
                perror("Command not found");
                _exit(1);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    free(command);
    return 0;
}
