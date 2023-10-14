#ifndef SHELL_H
#define SHELL_H

extern char *PROG_NAME;
extern char **environ;
/*static char buffer[BUF_SIZE];
static int buf_pos = 0;
static int buf_size = 0;*/
#define BUF_SIZE 1024

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void prompt(void);
char *read_command(void);
int execute(char *command, char *argv[], char *envp[]);
void handle_error(char *argv);
void process(char *input);
int search(char *command, char *argv[], char *envp[]);
void loop(void);
int check_built(char *command);
void my_exit(void);
ssize_t _getline(char *lineptr, size_t *n, FILE *stream);
#endif
