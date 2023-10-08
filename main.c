#include "shell.h"
/**
 * main - execution starts here
 *
 * Return: 0(runs successfully)
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt();
		command = read_command();
		if (command == NULL)
		{
			break;
		}
		execute(command);
		free(command);
	}
	return (0);
}
