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
#include <string.h>

#include "cmd.h"
#include "stack.h"

/*******************************************************************************
 * @brief   entry point of the program
 *
 * @param   argc   number of input arguments
 *          argv   array of given input arguments
 *
 * @return  0 if the programm finished without errors
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{
	stack_load();

	if (argc == 1) {
		cmd_list();
		return 0;
	}

	const char *sw = argv[1];

	if (strcmp(sw, SW_HELP) == 0) {
		cmd_help();
	}
	else if (strcmp(sw, SW_ADD) == 0) {
		cmd_add(argc, argv);
	}
	else if (strcmp(sw, SW_DEL) == 0) {
		cmd_del(argc, argv);
	}
	else if (strcmp(sw, SW_GET) == 0) {
		cmd_get(argc, argv);
	}
	else if (strcmp(sw, SW_LIST) == 0) {
		cmd_list();
	}
	else if (strcmp(sw, SW_CLEAR) == 0) {
		cmd_clear();
	}
	else {
		printf("unknown command: %s\n", sw);
	}

	stack_save();

	return 0;
}
