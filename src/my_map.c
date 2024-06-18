/*
** EPITECH PROJECT, 2017
** my_map.c
** File description:
**
*/

#include "sokoban.h"

void serialize_map(struct map *map, char *file_path)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	const char *error_display = "Can't display this map.\n";
	const char *error_player = "Can't display this map, player missing.\n";

	map->file_path = file_path;
	set_size_map(file_path, map);
	if (map->width <= 1 || map->height <= 1)
		report_error(error_display);
	map->boxes = malloc(map->width * map->height);
	map->content = malloc(sizeof(struct cell) * map->width * map->height);
	if (map->content == NULL || map->boxes == NULL)
		report_error(error_malloc);
	set_map(file_path, map);
	if (map->player == NULL)
		report_error(error_player);
}

void set_size_map(char *file_path, struct map *map)
{
	const char *error_invalid = "Fatal error: invalid char in map.\n";
	int c;
	FILE *file = fopen(file_path, "r");
	int found = 0;

	map->width = 0;
	map->height = 1;
	while ((c = getc(file)) != EOF) {
		if (c != '#' && c != 'O' && c != 'X' && c != 'P' &&
		c != ' ' && c != '\n')
			report_error(error_invalid);
		if (c == '\n') {
			map->height++;
			found = 1;
		}
		else if (found == 0) {
			map->width++;
		}
	}
	map->height--;
	fclose(file);
}

void set_map(char *file_path, struct map *m)
{
	int c;
	int x = 0;
	int y = 1;
	int i = 0;
	FILE *file = fopen(file_path, "r");

	for (i = 0; (c = getc(file)) != EOF && i < m->width * m->height; i++) {
		if (c == '\n') {
			y++;
			x = 0;
			i--;
		}
		else {
			m->content[i] = get_cell_instance(i, x, y,
			set_cell_map(c));
			manage_entity(m, c, m->content[i]);
			x++;
		}
	}
	fclose(file);
}

void display_map(struct map *map)
{
	for (int i = 0; i < map->width * map->height; i++) {
		if (i % (map->width) == 0)
			mvaddch(map->content[i].y, map->content[i].x, '\n');
		if (map->player != NULL && map->player->id == i) {
			mvaddch(map->content[i].y, map->content[i].x, 'P');
			continue;
		}
		if (i != 0 && box_at_cell(map, i)) {
			mvaddch(map->content[i].y, map->content[i].x, 'X');
			continue;
		}
		if (map->content[i].state == 2)
			mvaddch(map->content[i].y, map->content[i].x, ' ');
		else if (map->content[i].state == 0)
			mvaddch(map->content[i].y, map->content[i].x, '#');
		else
			mvaddch(map->content[i].y, map->content[i].x, 'O');
	}
}

int set_cell_map(char value)
{
	if (value == '#')
		return (0);
	else if (value == 'O')
		return (1);
	else
		return (2);
}