#include "shell.h"
int cd(char *argv[])
{
	char *new_directory, *current, *slash, *ptr;

	if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
	{
		new_directory = getenv("HOME");
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		new_directory = getenv("OLDPWD");
	}
	else if (strcmp(argv[1], "..") == 0)
	{
		current = getcwd(NULL, 0);
		slash = NULL;
		for (ptr = current; *ptr != '\0'; ptr++)
		{
			if (*ptr == '/')
			{
				slash = ptr;
			}
		}
		if (slash != NULL)
		{
			*slash = '\0';
			new_directory = current;
		}
		else
		{
			new_directory = "/";
		}
		free (current);
	}
	else
	{
		new_directory = argv[1];
	}
	if (new_directory == NULL)
	{
		fprintf(stderr, "$HOME not set\n");
	}

	current = getcwd(NULL, 0);

	if (chdir(new_directory) == 0)
	{
		setenv("OLDPWD", current, 1);
		setenv("PWD", getcwd(NULL, 0), 1);
	}
	else
	{
		fprintf(stderr, "%s can't cd to %s\n", PROG_NAME, argv[1]);
	}
	free(current);
	return (0);
}
