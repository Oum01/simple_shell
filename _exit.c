#include "shell.h"

/**
 * __exit - function that help to
 * exit from the program with the
 * status of the last command
 * executed
 *
 */
void __exit(void)
{
	_exit(_status_code(GET_STATUS, 0));
}
