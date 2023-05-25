#include "shell.h"

/**
 * _status_code - function that will keep track of
 * status in the progam
 *
 * @action: action that will be applied to the status
 * @new_status: new status code
 * Return: current status (integer)
 */
int _status_code(status_action_t action, int new_status)
{
	static int status;

	if (action == UPDATE_STATUS)
		status = new_status;
	return (status);
}
