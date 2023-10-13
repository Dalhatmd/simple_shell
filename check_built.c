#include "shell.h"
int check_built(char *input)
{/*
	int i, fun;
	char *built_in[] = {"exit",
		"env"
	};
	void (*fun_pointers[])() = {my_exit};

	for (i = 0; built_in[i] != NULL; i++)
	{
		if (strcmp(input, built_in[i]) == 0)
		{
			fun = i;
			break;
		}
	}
	fun_pointers[fun]();
	return (-1);*/
	printf("%s success\n", input);
	return (1);
}
