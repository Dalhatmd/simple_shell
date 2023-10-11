#include "shell.h"
void process(char *input)
{
	char *envp[] = {NULL}, *token;
	char *tokens[1024];
	int count, status;

	token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	if (count > 0)
	{
		token[count] = '\0';
		status = execute(tokens[0], tokens, envp);
		if (status != 0)
		{
			search(tokens[0], tokens, envp);
		}
	}
}
