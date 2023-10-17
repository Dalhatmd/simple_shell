#include "shell.h"
ComMap com_map[] = {
	{"exit", my_exit},
	{"env", my_env},
	{"setenv", exec_setenv},
	{"unsetenv", exec_unsetenv},
	{"cd", cd},
	{NULL, NULL}
};
int exec_builtin(char *command, char *argv[], char *envp[])
{
	int i;

	(void)envp;
	for (i = 0; com_map[i].name != NULL;  i++)
	{
		if (strcmp(command, com_map[i].name) == 0)
		{
			return com_map[i].handler(argv);
		}
	}
	return (1);
}
int exec_setenv(char *argv[])
{
	int result;
	
	if (argv[1] != NULL && argv[2] != NULL)
	{
		result = setenv(argv[1], argv[2], 1);
		if (result != 0)
		{
			fprintf(stderr, "setenv: Unable to set environment variable\n");
		}
	}
	else
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
	}
	return (0);
}

int exec_unsetenv(char *argv[])
{
	int result;

	if (argv[1] != NULL)
	{
		result = unsetenv(argv[1]);
		if (result != 0)
		{
			fprintf(stderr, "unsetenv: Unable to unset environment variable\n");
		}
	}
	else
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
	}
	return (0);
}
