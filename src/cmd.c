#include "cmd.h"
#include <stdio.h>

void cmd_help(void)
{
	printf("help page for program 'dstack'\n");
	printf("------------------------------\n");
	printf("-a <path>     adds a patch to the stack\n");
	printf("-d <index>    deletes the path with the index\n");
	printf("--clear       deletes the whole path stack\n");
	printf("-l            lists all stored paths\n");
}
