/*******************************************************************************
 *
 * dstack
 * Copyright (C) 2020 Matthias Escher
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#include "stack.h"

#include <stdio.h>
#include <string.h>

/*
 * file where the stack will be persisted
 */
#define FILE_LOCATION "/tmp/dstack.cache"

/*
 * the maximum allowed length of a path
 */
#define MAX_PATH_LENGTH 80

/*
 * the maximum size of the stack
 */
#define MAX_STACK_SIZE 10

/*
 * counter of the current stack size
 */
static int g_stack_size = 0;

/*
 * stack which holds an array of paths
 */
static char g_stack[MAX_STACK_SIZE][MAX_PATH_LENGTH];

/*******************************************************************************
 * @brief   checks if the given index is in the allowed range
 *
 * If the index is lower than zero or greater than the current stack size, the
 * functin will return -1.
 *
 * @param   index   the index of an entr in the stack
 *
 * @return  0 if the index is in the allowed range
 *         -1 if the index is NOT in the allowed range
 *
 ******************************************************************************/
static int check_index(int index)
{
	int result = 0;

	if (index < 0) {
		printf("no negative index allowed!\n");
		result = -1;
	}
	else if (index >= MAX_STACK_SIZE) {
		printf("index must be small than %d\n", MAX_STACK_SIZE);
		result = -1;
	}

	return result;
}

/*******************************************************************************
 * @brief   adds the given path to the end of the directory stack
 *
 * @param   *path   the path which will be added to the stack
 *
 * @return  0 if adding the path succeed
 *         -1 if the path length was exceeded or the maximum stack size is
 *            already reached.
 *
 ******************************************************************************/
int stack_add(const char *path)
{

	if (strlen(path) > MAX_PATH_LENGTH) {
		printf("maximum path length exceeded: %lu of %d\n",
		       strlen(path), MAX_PATH_LENGTH);
		return -1;
	}
	else if (g_stack_size >= MAX_STACK_SIZE) {
		printf("maximum size of stack reached: %d\n", g_stack_size);
		return -1;
	}
	else {
		char *dest = &g_stack[g_stack_size][0];
		strcpy(dest, path);
		g_stack_size++;
		return 0;
	}
}

/*******************************************************************************
 * @brief   removes the path on the given index from the stack
 *
 * @param   index   the index of the path to remove
 *
 * @return  0 if removing the path succeed
 *         -1 if removing fails
 *
 ******************************************************************************/
int stack_remove(int index)
{

	if (check_index(index) == 0) {
		char *dest = &g_stack[index][0];
		*dest      = '\0';
		return 0;
	}
	else {
		return -1;
	}
}

/*******************************************************************************
 * @brief   returns a pointer to the path on the given index
 *
 * @param   index   the index of the path
 *
 * @return  the path on the index or NULL if the index was out of range
 *
 ******************************************************************************/
const char *stack_get(int index)
{
	if (check_index(index) != 0) {
		return NULL;
	}
	else {
		return (const char *)&g_stack[index][0];
	}
}

/*******************************************************************************
 * @brief   returns the size of the stack
 *
 * @param   none
 *
 * @return  the stack size
 *
 ******************************************************************************/
int stack_size()
{
	return g_stack_size;
}

/*******************************************************************************
 * @brief   prints the content of the stack to the terminal
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
void stack_print()
{
	printf("stack size: %d\n", g_stack_size);
	printf("----------------------------\n");

	for (int i = 0; i < g_stack_size; i++) {
		printf("%2d '%s'\n", i, stack_get(i));
	}

	printf("\n");
}

/*******************************************************************************
 * @brief   loads the stack from the file storage
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
void stack_load()
{
	FILE *fp = fopen(FILE_LOCATION, "r");

	if (fp == NULL) {
		printf("unable to open %s\n", FILE_LOCATION);
	}
	else {
		char buffer[MAX_PATH_LENGTH];

		while (fgets(buffer, MAX_PATH_LENGTH, fp) != NULL) {

			char *c = rindex(buffer, '\n');

			if (c != NULL) {
				*c = '\0';
			}

			stack_add(buffer);
		}

		fclose(fp);
	}
}

/*******************************************************************************
 * @brief   saves the current stack to the file storage
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
void stack_save()
{
	FILE *fp = fopen(FILE_LOCATION, "w");

	if (fp == NULL) {
		printf("unable to open %s\n", FILE_LOCATION);
	}
	else {
		for (int i = 0; i < g_stack_size; i++) {

			if (strlen(stack_get(i)) > 0) {
				fputs(stack_get(i), fp);
				fputs("\n", fp);
			}
		}
	}

	fclose(fp);
}

/*******************************************************************************
 * @brief   clears the whole stack
 *
 * @param   none
 *
 * @return  0 if the clear operation succeed
 *         -1 if anything went wrong
 *
 ******************************************************************************/
int stack_clear()
{
	int errors = 0;

	for (int i = 0; i < g_stack_size; i++) {
		errors += stack_remove(i);
	}

	if (errors == 0)
		return 0;
	else
		return -1;
}
