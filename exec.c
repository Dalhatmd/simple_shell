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
	char *envp[] = {NULL}, *args[100];
	char *token;
	int status, exec_result, i;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed\n");
		exit(1);
	}
	else if (pid == 0)
	{
		token = strtok(command, " ");
		i = 0;
                while (token != NULL)
                {
                        args[i++] = token;
                        token = strtok(NULL, " ");
                }
                args[i] = NULL;
                int exec_result = execve(args[0], args, envp);
                perror("");
                exit(exec_result);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
