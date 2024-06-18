/*
** EPITECH PROJECT, 2017
** my_random.c
** File description:
**
*/

#include "sokoban.h"

void serialize_random_map(struct map *map)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";

	map->width = crand(10, 40);
	map->height = crand(10, 40);
	map->content = malloc(sizeof(struct cell) *
		(map->width * map->height));
	if (map->content == NULL)
		report_error(error_malloc);
	set_random_map(map);
	set_borders(map);
	set_random_walls(map);
	set_random_boxes(map);
	set_random_player_placement(map);
}

void set_random_map(struct map *map)
{
	int cells_count = map->width * map->height;
	int i;
	int x = 0;
	int y = 0;

	for (i = 0; i < cells_count; i++) {
		if (i != 0 && i % map->width == 0) {
			x = 0;
			y++;
		}
		map->content[i] = get_cell_instance(i, x, y, 2);
		x++;
	}
}

void set_borders(struct map *map)
{
	int i;

	for (i = 0; i < map->width; i++)
		map->content[i].state = 0;
	for (i = 0; i < map->width; i++) {
		map->content[i + (map->width * map->height - map->width)].state
			= 0;
	}
	for (i = 0; i < map->width * map->height; i += map->width)
		map->content[i].state = 0;
	for (i = map->width - 1; i < map->width * map->height; i += map->width)
		map->content[i].state = 0;
}

int crand(int a, int b)
{
	return (rand() % (b - a) + a);
}
