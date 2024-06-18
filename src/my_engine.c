/*
** EPITECH PROJECT, 2017
** my_engine.c
** File description:
**
*/

#include "sokoban.h"

void process(struct map *map)
{
	int key;

	while (!game_finished(map) && !box_blocked(map)) {
		if (map->step == 0)
			display_menu(map);
		if (map->step == 1) {
			init_screen();
			display_map(map);
		}
		else if (map->step == 2) {
			display_select(map);
			return;
		}
		refresh();
		if (game_finished(map) || box_blocked(map))
			break;
		key = getch();
		event_on_key(key, map);
	}
	endwin();
}

void event_on_key(int key, struct map *map)
{
	struct cell requested_cell = get_requested_cell(key, map, 1);
	struct cell distance_cell = get_requested_cell(key, map, 2);

	if (key == ' ') {
		map->boxes_len = 0;
		set_map(map->file_path, map);
	}
	if (requested_cell.x == 0 && requested_cell.y == 0)
		return;
	if (box_at_cell(map, requested_cell.id) && !box_at_cell(map,
	distance_cell.id) && distance_cell.state >= 1)
		push_box(requested_cell, distance_cell, map);
	if (!box_at_cell(map, requested_cell.id) && requested_cell.state != 0)
		move_player(requested_cell, map);
}

struct cell get_requested_cell(int key, struct map *map, int dist)
{
	const int left = 259;
	const int right = 258;
	const int top = 260;
	const int bot = 261;
	int x = map->player->x;
	int y = map->player->y;

	if (key != top && key != bot && key != left && key != right)
		return (get_cell_instance(0, 0, 0, 0));
	if (key == left)
		y = map->player->y - dist;
	if (key == right)
		y = map->player->y + dist;
	if (key == top)
		x = map->player->x - dist;
	if (key == bot)
		x = map->player->x + dist;
	for (int i = 0; i < map->width * map->height; i++)
		if (map->content[i].x == x && map->content[i].y == y)
			return (map->content[i]);
	return (get_cell_instance(0, 0, 0, 0));
}