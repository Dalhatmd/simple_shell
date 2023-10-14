#include "shell.h"
char *PROG_NAME;
int main(int argc, char *argv[])
{
	(void)argc;
	PROG_NAME = argv[0];
	loop();
	return (0);
}

