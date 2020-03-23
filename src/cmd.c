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
#include "cmd.h"

#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "version.h"

static int str_to_int(const char *s)
{
	int result = 0;
	int len    = (int)strlen(s);

	for (int i = 0; i < len; i++) {
		result = result * 10 + (s[i] - '0');
	}

	return result;
}

int cmd_is_switch(const char *s, const char *sw)
{
	if (strcmp(s, sw) == 0)
		return 1;
	else
		return 0;
}

int cmd_help(void)
{
	printf("help page for program 'dstack'\n");
	printf("------------------------------\n");
	printf("-a <path>     adds a patch to the stack\n");
	printf("-d <index>    deletes the path with the index\n");
	printf("--clear       deletes the whole path stack\n");
	printf("-l            lists all stored paths\n");

	return 0;
}

int cmd_add(int argc, char *argv[])
{

	if (argc != 3) {
		printf("wrong usage, expected: %s <path>\n", SW_ADD);
	}
	else {
		stack_add(argv[2]);
	}
}

int cmd_del(int argc, char *argv[])
{

	if (argc != 3) {
		printf("Wrong parameter count, expected: %s <index>\n", SW_DEL);
		return -1;
	}
	else {
		int index = str_to_int(argv[2]);
		return stack_remove(index);
	}
}

int cmd_list()
{
	stack_print();
	return 0;
}

int cmd_clear()
{
	return stack_clear();
}

int cmd_get(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Wrong parameter count, expected: %s <index>\n", SW_GET);
		return -1;
	}
	else {
		int index = str_to_int(argv[2]);

		const char *s = stack_get(index);

		if (s != NULL) {
			printf("%s\n", s);
			return 0;
		}
		else {
			return -1;
		}
	}
}

int cmd_version()
{
	printf("dstack %s\n", DSTACK_VERSION);
	return 0;
}
