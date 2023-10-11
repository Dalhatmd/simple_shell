#include "shell.h"
int search(char *command, char *argv[], char *envp[])
{
	char *path, *path_copy, *path_dir, command_path[1024];
	int status;

	path = getenv("PATH");
	path_copy = strdup(path);
	path_dir = strtok(path_copy, ":");

	while (path_dir != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", path_dir, command);
		status = execute(command_path, argv, envp);
		if (status == 0)
		{
			free(path_copy);
			return(0);
		}
		path_dir = strtok(NULL, ":");
	}
	fprintf(stderr, "%s: command not found\n", command);
	free(path_copy);
	return (127);
}
