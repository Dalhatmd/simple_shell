#include "shell.h"
int main()
{
	char *command;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
	printf("$ ");
	read = getline(&command, &len, stdin);
	if (read == -1)
	{
		exit(0);
	}
	else
	{
		printf("%s\n", command);
	}
	}
	free(command);
	return 0;
}
