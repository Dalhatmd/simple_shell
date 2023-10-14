#include "shell.h"
int search(char *command, char *argv[], char *envp[])
{
	char *path, *path_copy, *path_dir, command_path[1024];
	int status;

	path = getenv("PATH");
	path_copy = strdup(path);
	path_dir = _strtok(path_copy, ":");

	while (path_dir != NULL)
	{
		strcpy(command_path, path_dir);
		strcat(command_path, "/");
		strcat(command_path, command);
		status = execute(command_path, argv, envp);
		if (status == 0)
		{
			free(path_copy);
			return(0);
		}
		path_dir = _strtok(NULL, ":");
	}
	/* add function to check for built_in command. if it returns not */
	fprintf(stderr, "%s: No such file or directory\n", PROG_NAME);
	free(path_copy);
	return (0);
}
