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
