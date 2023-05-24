#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

void shell_prompt(void);
void execute_command(char *command);
void shell_loop(void);

#endif
