#include <stdio.h>

#include "cmd.h"
#include "stack.h"

void test(void)
{
	printf("testing...\n");

	printf("---\n");
	printf("current size: %d\n\n", stack_size());

	stack_add("/tmp/mozilla");
	stack_add("~/Projekte");
	stack_add("/usr/local/bin");

	printf("---\n");
	printf("current size: %d\n\n", stack_size());

	stack_print();
}

int main(int argc, char *argv[])
{

	test();

	return 0;
}
