#ifndef STACK_H
#define STACK_H

#define MAX_PATH_LENGTH 50
#define MAX_STACK_SIZE 10

void        stack_print(void);
void        stack_add(const char *path);
const char *stack_get(int index);
int         stack_size(void);

#endif // STACK_H
