#include "shell.h"

/**
 * _global_variables - function that helps
 * to access global variables everywhere
 * in the program
 *
 * @action: to be applied to the global variables
 * @str: to be assigned to program name
 * on the actions
 * Return: (void *)
 */
void *_global_variables(global_action_t action, char *str)
{
	static int line;
	static char *program_name;

	if (action == SET_PROGRAM_NAME)
		program_name = str;
	if (action == GET_PROGRAM_NAME)
		return (program_name);
	if (action == INCREMENT_LINE)
		line++;
	if (action == GET_LINE_NUMBER)
		return (&line);
	return (NULL);
}
