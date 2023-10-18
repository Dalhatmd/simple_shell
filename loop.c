#include "shell.h"
void loop(void)
{
	char *command = NULL;
	char *token;
	size_t command_size = 0;
	ssize_t b_read;

	command = malloc(BUF_SIZE);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		printf("$ ");
		fflush(stdout);
		}
		b_read = _getline(command, &command_size, stdin);
		if (b_read == -1)
		{
			break;
		}
		if (b_read > 0 && command[b_read - 1] == '\n')
		{
			command[b_read - 1] = '\0';
		}
		token = strtok(command, ";");
		while (token != NULL)
		{
			process(token);
			token = strtok(NULL, ";");
		}
	}
	free(command);
}
