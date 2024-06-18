/*
** EPITECH PROJECT, 2017
** my_utils.c
** File description:
**
*/

#include "sokoban.h"

int game_finished(struct map *map)
{
	int i;

	if (map->boxes_len == 0)
		return (0);
	for (i = 0; i < map->boxes_len; i++)
		if (map->content[map->boxes[i].id].state != 1)
			return (0);
	return (1);
}

int box_blocked(struct map *map)
{
	int i;

	for (i = 0; i < map->boxes_len; i++)
		if (map->content[map->boxes[i].id].state != 1 &&
		get_block_count(map->boxes[i], map) > 1)
			return (1);
	return (0);
}

int get_block_count(struct entity box, struct map *map)
{
	int block_count = 0;

	if (can_move_player(map, box.id + 1) &&
		can_move_player(map, box.id + map->width))
		block_count += 2;
	if (can_move_player(map, box.id - 1) &&
		can_move_player(map, box.id - map->width))
		block_count += 2;
	if (can_move_player(map, box.id + 1) &&
		can_move_player(map, box.id - map->width))
		block_count += 2;
	if (can_move_player(map, box.id - 1) &&
		can_move_player(map, box.id + map->width))
		block_count += 2;
	return (block_count);
}

void manage_entity(struct map *map, char c, struct cell cell)
{
	if (c == 'P')
		map->player = get_entity_star(cell.id, cell.x, cell.y);
	if (c == 'X') {
		map->boxes[map->boxes_len] = get_entity(cell.id, cell.x,
		cell.y);
		map->boxes_len++;
	}
}

int box_at_cell(struct map *map, int index)
{
	int i;

	for (i = 0; i < map->boxes_len; i++)
		if (map->boxes[i].id == index)
			return (1);
	return (0);
}
