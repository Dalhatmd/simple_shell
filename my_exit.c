#include "shell.h"
int my_exit(char *status)
{
	int exit_status;

	exit_status = atoi(status);
	exit(exit_status);
}
