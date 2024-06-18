/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include "sokoban.h"

struct map *get_map_instance(void)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	struct map *map = malloc(sizeof(struct map));

	if (map == NULL)
		report_error(error_malloc);
	map->width = 0;
	map->height = 0;
	return (map);
}

struct cell get_cell_instance(int id, int x, int y, int state)
{
	struct cell cell;

	cell.id = id;
	cell.x = x;
	cell.y = y;
	cell.state = state;
	return (cell);
}

struct entity *get_entity_star(int id, int x, int y)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	struct entity *entity = malloc(sizeof(struct entity));

	if (entity == NULL)
		report_error(error_malloc);
	entity->id = id;
	entity->x = x;
	entity->y = y;
	return (entity);
}

struct entity get_entity(int id, int x, int y)
{
	struct entity entity;

	entity.id = id;
	entity.x = x;
	entity.y = y;
	return (entity);
}

void get_help(void)
{
	const char *header = "USAGE\n	   ./my_sokoban map\n"
	"	   ./my_sokoban\n\n";
	const char *content = "DESCRIPTION\n	   map	"
	"file representing the warehouse map, containing '#' for walls,\n"
	"		'P' for the player, 'X' for boxes and 'O' for "
	"storage locations.\n";

	my_put_str(header);
	my_put_str(content);
	exit(0);
}