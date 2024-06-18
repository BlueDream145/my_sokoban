/*
** EPITECH PROJECT, 2017
** my_random_entity.c
** File description:
**
*/

#include "sokoban.h"

void set_random_walls(struct map *map)
{
	int cells_count = map->width * map->height;
	int walls_len = crand(cells_count / 3 / 3, cells_count / 3 / 2);
	int current_cell = crand(0, cells_count);
	int i;

	for (i = 0; i < walls_len; i++) {
		while (cell_free(map, current_cell, 0) == 0)
			current_cell = crand(map->width + 2, cells_count - 1);
		map->content[current_cell].state = 0;
		current_cell = crand(0, cells_count);
	}
}

void set_random_player_placement(struct map *map)
{
	int cells_count = map->width * map->height;
	int current_cell = crand(0, cells_count);

	while (cell_free(map, current_cell, 0) == 0)
			current_cell = crand(map->width + 2, cells_count - 1);
	map->player = get_entity_star(current_cell,
	map->content[current_cell].x,
	map->content[current_cell].y);
}

void set_random_boxes(struct map *map)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	int cells_count = map->width * map->height;
	int current_cell = crand(0, cells_count - 1);
	int i;

	map->boxes_len = crand(1, 7);
	map->boxes = malloc(sizeof(struct entity) * map->boxes_len);
	if (map->boxes == NULL)
		report_error(error_malloc);
	for (i = 0; i < map->boxes_len; i++) {
		while (box_free(map, current_cell) == 0)
			current_cell = crand(map->width + 2, cells_count - 1);
		map->boxes[i] = get_entity(current_cell,
		map->content[current_cell].x,
		map->content[current_cell].y);
		current_cell = crand(0, cells_count - 1);
		while (cell_free(map, current_cell, 0) == 0)
			current_cell = crand(map->width + 2, cells_count - 1);
		map->content[current_cell].state = 1;
		current_cell = 0;
	}
}

int cell_free(struct map *map, int cell, int var)
{
	if (map->content[cell].state != 2)
		return (0);
	if (box_at_cell(map, cell))
		return (0);
	if (var != 0 && get_block_count(get_entity(cell, map->content[cell].x,
	map->content[cell].y), map) >= 2)
		return (0);
	return (1);
}

int box_free(struct map *map, int cell)
{
	if (map->content[cell].state != 2)
		return (0);
	if (box_at_cell(map, cell))
		return (0);
	if (map->content[cell + 1].state != 2)
		return (0);
	if (map->content[cell -1].state != 2)
		return (0);
	if (map->content[cell + map->width].state != 2)
		return (0);
	if (map->content[cell - map->width].state != 2)
		return (0);
	return (1);
}