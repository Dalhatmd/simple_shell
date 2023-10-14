#include "shell.h"
static char buffer[BUF_SIZE];
static int buf_pos = 0;
static int buf_size = 0;
ssize_t _getline(char *lineptr, size_t *n, FILE *stream)
{
	ssize_t idx = 0;
	int read_char;

	while (1)
	{
		if (buf_pos >= buf_size)
		{
			buf_size = read(fileno(stream), buffer, BUF_SIZE);
			buf_pos = 0;
		}
		if (buf_size <= 0)
		{
			if (idx == 0)
			{
				return (-1);
			}
			lineptr[idx] = '\0';
			return (idx);
		}

		read_char = buffer[buf_pos++];
		if (read_char == '\n')
		{
			lineptr[idx] = '\0';
			return (idx);
		}
		else
		{
			if ((size_t)idx < (*n - 1))
			{
				lineptr[idx++] = read_char;
			}
			else
			{
				lineptr[idx] = '\0';
				return (idx);
			}
		}
	}
}
