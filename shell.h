#ifndef SHELL_H
#define SHELL_H

extern char **environ;
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include<stdlib.h>

void execute(char *command);

#endif
