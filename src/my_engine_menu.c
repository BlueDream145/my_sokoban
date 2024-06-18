/*
** EPITECH PROJECT, 2017
** my_engine_menu.c
** File description:
**
*/

#include "sokoban.h"

void display_menu(struct map *map)
{
	WINDOW *w = newwin( 9, 10, 5, 5 );
	char content[4][7] = { "Play", "Map", "Random", "Exit" };
	int i;
	int ch;

	initscr();
	w = newwin( 9, 10, 5, 5 );
	init_menu(w);
	init_first_menu(w);
	first_display_menu(w);
	while ((ch = wgetch(w)) != 'q') {
		if (i + 1 <= 4)
			mvwprintw(w, i + 1, 2, "%s", content[i]);
		i = key_event(map, ch, i);
		if (i == 42)
			break;
		menu_write_highlight(w, i);
	}
	delete_window(w);
	if (map->step == 0)
		exit(0);
}

int first_display_menu(WINDOW *w)
{
	char content[4][7] = { "Play", "Map", "Random", "Exit" };
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

int key_event(struct map *map, int ch, int i)
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
	if (ch == 10)
		i = entry_selected_event(map, i);
	return (i);
}

int entry_selected_event(struct map *map, int i)
{
	if (i == 0)
		map->step = 1;
	else if (i == 1)
		map->step = 2;
	if (i == 2) {
		serialize_random_map(map);
		map->step = 1;
		map->random = 1;
	}
	i = 42;
	return (i);
}

void menu_write_highlight(WINDOW *w, int i)
{
	char content[4][7] = { "Play", "Map", "Random", "Exit" };

	wattron(w, A_STANDOUT);
	mvwprintw(w, i + 1, 2, "%s", content[i]);
	wattroff(w, A_STANDOUT);
}