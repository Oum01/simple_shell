#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdarg.h>

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

/**
 * enum global_action_e - actions that will be
 * applied to global variables
 *
 * @GET_LINE_NUMBER: to retrieve line number
 * @GET_PROGRAM_NAME: to retrieve prgram
 * name
 * @SET_PROGRAM_NAME: to set program name
 * @INCREMENT_LINE: to increment line each time
 */
typedef enum global_action_e
{
	GET_LINE_NUMBER,
	GET_PROGRAM_NAME,
	SET_PROGRAM_NAME,
	INCREMENT_LINE
} global_action_t;

int _status_code(status_action_t action, int new_status);
void _env(void);
void __exit(void);
char **split(char *line, const char *del);
char *_strdup(const char *str);
int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
void execute(char **tokens, char *line);
void *_global_variables(global_action_t action, char *str);
void _fprintf(int fd, const char *format, ...);
char *remove_comments(char *s);
#endif
