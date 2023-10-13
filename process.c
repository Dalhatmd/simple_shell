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
		if (strcmp(tokens[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		if (strcmp(tokens[0], "env") == 0)
		{
			printf("env\n");
		}
		status = execute(tokens[0], tokens, envp);
		if (status != 0)
		{
			search(tokens[0], tokens, envp);
		}
		else if (status == 1)
		{
			check_built(input);
		}
	}
}
