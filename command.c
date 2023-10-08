#include "shell.h"
/**
 * read_command - reads command from stdin
 *
 * Return: returns the command after reading
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	bytes_read = getline(&command, &len, stdin);
	if (bytes_read == -1)
	{
		printf("\n");
		return (NULL);
	}
	if (bytes_read > 0 && command[bytes_read - 1] == '\n')
	{
		command[bytes_read - 1] = '\0';
	}
	return (command);
}
