#include "shell.h"
int my_exit(char *argv[])
{
	int exit_status;

	if (argv[1] != NULL)
	{
		exit_status = atoi(argv[1]);
		exit(exit_status);
	}
	else
	{
		exit(0);
	}
}
