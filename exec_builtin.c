#include "shell.h"
int exec_builtin(char *command, char *argv[], char *envp[])
{
	if (strcmp(command, "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			my_exit(argv[1]);
		}
		else
		{
			exit(0);
		}
	}
	else if (strcmp(command, "env") == 0)
	{
		char **env = environ;
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return (0);
	}
	return (1);
}
