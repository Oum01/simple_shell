#ifndef SHELL_H
#define SHELL_H
<<<<<<< HEAD
=======

#include <unistd.h>
#include <stdlib.h>
>>>>>>> 52badf5841e3702c0ac917ae3eb80b72a5339f18
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * enum status_action_e - actions to be applied to
 * status code
 *
 * @UPDATE_STATUS: action that will be used to
 * update status code
 * @GET_STATUS: action that will be used to
 * get status
 */
typedef enum status_action_e
{
	UPDATE_STATUS,
	GET_STATUS
} status_action_t;

int _status_code(status_action_t action, int new_status);
void _env(void);
void __exit(void);
char **split(char *line, const char *del);
char *_strdup(const char *str);
int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
void execute(char **tokens);
#endif
