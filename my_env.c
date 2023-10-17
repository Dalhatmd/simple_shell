#include "shell.h"
int my_env(char *argv[])
{
	char **env = environ;

	(void)argv;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
