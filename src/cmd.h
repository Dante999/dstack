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
#ifndef CMD_H
#define CMD_H

#define SW_HELP "-h"
#define SW_ADD "-a"
#define SW_DEL "-d"
#define SW_GET "-g"
#define SW_LIST "-l"
#define SW_CLEAR "--clear"
#define SW_VERSION "--version"

int cmd_is_switch(const char *s, const char *sw);
int cmd_get(int argc, char *argv[]);
int cmd_add(int argc, char *argv[]);
int cmd_del(int argc, char *argv[]);
int cmd_help(void);
int cmd_list(void);
int cmd_clear(void);
int cmd_version(void);

#endif // CMD_H
