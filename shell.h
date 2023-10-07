#ifndef SHELL_H
#define SHELL_H

extern char **environ;
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
void execute(char *command);

#endif
