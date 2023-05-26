#include "shell.h"

/**
 * _env - function that prints
 * what inside the environment
 *
 * Return: void
 */
void _env(void)
{
	char **envs;

	envs = __environ;
	while (*envs)
	{
		_fprintf(1, "%s\n", *envs);
		envs++;
	}
}
