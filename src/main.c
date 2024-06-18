/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "sokoban.h"

int main(int ac, char **as)
{
	const char *error_bad_usage = "Bad usage.\n";
	char *default_map = "../maps/map_2";
	struct map *map = get_map_instance();

	srand(time(NULL));
	if (ac != 1 && ac != 2)
		report_error(error_bad_usage);
	if (ac == 2 && ((as[1][0] == '-' && as[1][1] == 'h') ||
	as[1][0] == 'h'))
		get_help();
	if (ac == 1)
		serialize_map(map, default_map);
	else {
		serialize_map(map, as[1]);
		map->step = 1;
	}
	process(map);
	dispose(map);
	return (0);
}

void dispose(struct map *map)
{
	free(map->boxes);
	free(map->content);
	free(map->player);
	free(map->file_path);
	free(map);
}
