#include "shell.h"
void loop(char *argv[])
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t b_read;

	while (1)
	{
		printf("$ ");
		b_read = getline(&command, &command_size, stdin);
		if (b_read == -1)
		{
			break;
		}
		if (b_read > 0 && command[b_read - 1] == '\n')
		{
			command[b_read - 1] = '\0';
		}
		process(command);
	}
	free(command);
}
