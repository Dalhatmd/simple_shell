#include "shell.h"
void process(char *input)
{
	char *token;
	char *tokens[1024];
	int count, result, status;

	char *envp[] = {NULL};
	count = 0;
	token = _strtok(input, " ");
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		token = _strtok(NULL, " ");
	}
	if (count > 0)
	{
		tokens[count] = '\0';
	/*	if (access(tokens[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", PROG_NAME);
		}*/
			result = exec_builtin(tokens[0], tokens, envp);
			if (result == 1)
			{
				status = execute(tokens[0], tokens, envp);
				if (status != 0)
				{
					search(tokens[0], tokens, envp);
				}
			}
		}
	}

