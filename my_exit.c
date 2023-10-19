#include "shell.h"
int my_exit(char *argv[])
{
	int exit_status;

	exit_status = 0;
	if (argv[1] != NULL && is_valid(argv[1]))
	{
		exit_status = atoi(argv[1]);
		exit(exit_status);
	}
	else
	{
		fprintf(stderr, "Error: Argument not valid for exit\n");
		return (1);
	}
}

int is_valid(char *str)
{
	int i, number;

	if (str[0] == '\0')
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	number = atoi(str);
	return (number >= 0);
}
