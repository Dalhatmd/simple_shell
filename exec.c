#include "shell.h"
/**
 * execute - executes a command given
 *
 * @command: input command to be executed
 *
 * Return: No return
 */
void execute(char *command)
{
	char *envp[] = {NULL};
	int status, exec_result;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed\n");
		exit(1);
	}
	else if (pid == 0)
	{
		char *argv[2];
		argv[0] = command;
		argv[1] = NULL;
		exec_result = execve(command, argv, envp);

		exit(exec_result);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
