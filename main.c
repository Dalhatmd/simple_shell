#include "shell.h"
/**
 * main - execution starts here
 *
 * Return: 0(runs successfully)
 */
int main(int argc, char **argv)
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

void handle_error(char *argv)
{
/*        fprintf(stderr, "%s: No such file or directory \n", argv[0]);
*/}
