#include "shell.h"
void execute(char *command)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Cannot fork\n");
	}
	if (pid > 0)
	{
		execve("/bin/ls", &command, environ);
	}

}
