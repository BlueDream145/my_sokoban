/*
** EPITECH PROJECT, 2017
** my_engine_select.c
** File description:
**
*/

#include "sokoban.h"

void display_select(struct map *map)
{
	WINDOW *w = newwin(9, 10, 5, 5);
	char content[4][7] = { "Map_1", "Map_2", "Map_3", "Map_4" };
	int i;
	int ch;

	initscr();
	w = newwin( 9, 10, 5, 5 );
	init_menu(w);
	init_first_menu(w);
	first_display_select(w);
	while ((ch = wgetch(w)) != 'q') {
		if (i + 1 <= 4)
			mvwprintw(w, i + 1, 2, "%s", content[i]);
		i = select_key_event(map, ch, i);
		if (i == 42 || map->step == 1)
			break;
		select_write_highlight(w, i);
	}
	delete_window(w);
}

int first_display_select(WINDOW *w)
{
	char content[4][7] = { "Map_1", "Map_2", "Map_3", "Map_4" };
	int i;

	for (i = 0; i < 4; i++) {
		if (i == 0)
			wattron(w, A_STANDOUT);
		else
			wattroff(w, A_STANDOUT);
		mvwprintw(w, i + 1, 2, "%s", content[i]);
	}
	return (i);
}

int select_key_event(struct map *map, int ch, int i)
{
	if (ch == KEY_UP) {
		i--;
		if (i < 0)
			i = 3;
	}
	if (ch == KEY_DOWN) {
		i++;
		if (i > 3)
			i = 0;
	}
	if (ch == 10 || ch == KEY_ENTER)
		i = select_entry_event(map, i);
	return (i);
}

int select_entry_event(struct map *map, int i)
{
	map = get_map_instance();
	if (i == 0)
		serialize_map(map, "../maps/map");
	else if (i == 1)
		serialize_map(map, "../maps/map_2");
	if (i == 2)
		serialize_map(map, "../maps/map_3");
	else if (i == 3)
		serialize_map(map, "../maps/map_4");
	map->step = 1;
	i = 42;
	process(map);
	return (i);
}

void select_write_highlight(WINDOW *w, int i)
{
	char content[4][7] = { "Map_1", "Map_2", "Map_3", "Map_4" };

	wattron(w, A_STANDOUT);
	mvwprintw(w, i + 1, 2, "%s", content[i]);
	wattroff(w, A_STANDOUT);
}