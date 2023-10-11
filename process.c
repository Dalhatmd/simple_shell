#include "shell.h"
void process(char *input)
{
	char *envp[] = {NULL};
	char *token;
	char *tokens[1024];
	int count, status;

	count = 0;
	token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	if (count > 0)
	{
		tokens[count] = '\0';
		status = execute(tokens[0], tokens, envp);
		if (status != 0)
		{
			search(tokens[0], tokens, envp);
		}
	}
}
