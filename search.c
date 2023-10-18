#include "shell.h"
int search(char *command, char *argv[], char *envp[])
{
	char *path, *path_copy, *path_dir, command_path[1024];
	int status;

	status = 1;
	path = getenv("PATH");
	path_copy = strdup(path);
	path_dir = _strtok(path_copy, ":");

	while (path_dir != NULL)
	{
		strcpy(command_path, path_dir);
		strcat(command_path, "/");
		strcat(command_path, command);
		if (access(command_path, X_OK) == 0)
		{
			status = execute(command_path, argv, envp);
			if (status == 0)
			{
				break;
			}
		}
		path_dir = _strtok(NULL, ":");
	}
	free(path_copy);
	if (status == 1)
	{
		fprintf(stderr, "%s: no such file or directory\n", PROG_NAME);
	}
	return (0);
}
