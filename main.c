#include "shell.h"
int main(void)
{
	char *command = NULL;
	char *envp[] = {NULL};
	size_t len = 0;
	ssize_t bytes_read;
	int status;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&command, &len, stdin);
		if (bytes_read == -1)
		{
			printf("\n");
			exit(1);
		}
		if (bytes_read > 0 && command[bytes_read - 1] == '\n')
		{
			command[bytes_read - 1] = '\0';
		}
		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			char *argv[] = {command, NULL};
			execve(command, argv, envp);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				printf("child exited with status%d\n", WEXITSTATUS(status));
			}
			else if(WIFSIGNALED(status))
			{
				printf("Child terminated with signal %d\n", WTERMSIG(status));
			}

		}
	}
	free(command);
	return (0);
}
