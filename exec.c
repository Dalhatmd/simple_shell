#include "shell.h"
/**
 * execute - executes a command given
 *
 * @command: input command to be executed
 *
 * Return: No return
 */
int execute(char *command, char *argv[], char *envp[])
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed\n");
		return(-1);
	}
	else if (pid == 0)
	{
		execve(command, argv, envp);
		fprintf(stderr, "%s: command not found \n", command);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}
