#include "stack.h"

#include <stdio.h>
#include <string.h>

#define MAX_PATH_LENGTH 50
#define MAX_STACK_SIZE 10


static int  g_stack_size = 0;
static char g_stack[MAX_STACK_SIZE][MAX_PATH_LENGTH];

void stack_add(const char *path)
{

	if (strlen(path) > MAX_PATH_LENGTH) {
		printf("maximum path length exceeded: %lu of %d\n",
		       strlen(path), MAX_PATH_LENGTH);
		return;
	}
	else if (g_stack_size >= MAX_STACK_SIZE) {
		printf("maximum size of stack reached: %d\n", g_stack_size);
		return;
	}
	else {
		char *dest = &g_stack[g_stack_size][0];
		strcpy(dest, path);
		g_stack_size++;
	}
}

const char *stack_get(int index)
{
	if (index < 0) {
		printf("no negative index allowed!\n");
		return NULL;
	}
	else if (index >= MAX_STACK_SIZE) {
		printf("index must be small than %d\n", MAX_STACK_SIZE);
		return NULL;
	}
	else {
		return (const char *)&g_stack[index][0];
	}
}

int stack_size()
{
	return g_stack_size;
}

void stack_print()
{
	for (int i = 0; i < g_stack_size; i++) {
		printf("%2d '%s'\n", i, &g_stack[i][0]);
	}

	printf("\n");
}
