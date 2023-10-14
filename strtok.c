#include "shell.h"
static char *strtok_ptr = NULL;

char *_strtok(char *str, const char *delim)
{
	char *start;
	if (str != NULL)
	{
		strtok_ptr = str;
	}
	if (strtok_ptr == NULL)
	{
		return (NULL);
	}
	while (*strtok_ptr != '\0' && is_delim(*strtok_ptr, delim))
	{
		strtok_ptr++;
	}

	if (*strtok_ptr == '\0')
	{
		strtok_ptr = NULL;
		return (NULL);
	}
	start = strtok_ptr;
	while (*strtok_ptr != '\0' && !is_delim(*strtok_ptr, delim))
	{
		strtok_ptr++;
	}
	if (*strtok_ptr != '\0')
	{
		*strtok_ptr = '\0';
		strtok_ptr++;
	}
	return (start);
}

int is_delim(char c, const char *delim)
{
	int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
		{
			return (1);
		}
	}
	return (0);
}
