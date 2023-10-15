#include "shell.h"
int exec_builtin(char *command, char *argv[], char *envp[])
{
	char **env = environ;

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
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return (0);
	}
	else if (strcmp(command, "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL)
		{
			exec_setenv(argv[1], argv[2]);
		}
		else
		{
			fprintf(stderr, "setenv: Failed\n");
		}
		return (0);
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		if (argv[1] != NULL)
		{
			exec_unsetenv(argv[1]);
		}
		else
		{
			fprintf(stderr, "unsetenv: Failed\n");
		}
		return (0);
	}
	return (1);
}

void exec_setenv(char *var, char *val)
{
	int result;

	result = setenv(var, val, 1);
	if (result != 0)
	{
		fprintf(stderr, "setenv: Unable to set environment variable\n");
	}
}

void exec_unsetenv(char *var)
{
	int result;

	result = unsetenv(var);
	if (result != 0)
	{
		fprintf(stderr, "unsetenv: Unable to unset environment variable\n");
	}
}
