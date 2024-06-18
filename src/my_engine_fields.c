/*
** EPITECH PROJECT, 2017
** my_engine_fields.c
** File description:
**
*/

#include "sokoban.h"

void push_box(struct cell requested_cell, struct cell distance_cell,
struct map *map)
{
	int i;

	map->player->x = requested_cell.x;
	map->player->y = requested_cell.y;
	map->player->id = requested_cell.id;
	for (i = 0; i < map->boxes_len; i++)
		if (map->boxes[i].x == requested_cell.x &&
		map->boxes[i].y == requested_cell.y) {
			map->boxes[i].x = distance_cell.x;
			map->boxes[i].y = distance_cell.y;
			map->boxes[i].id = distance_cell.id;
		}
}

void move_player(struct cell requested_cell, struct map *map)
{
	map->player->x = requested_cell.x;
	map->player->y = requested_cell.y;
	map->player->id = requested_cell.id;
}

int can_move_player(struct map *map, int index)
{
	if (map->content[index].state == 0)
		return (1);
	return (0);
}