/*
** EPITECH PROJECT, 2017
** sokoban.h
** File description:
** 
*/

#ifndef sokoban_
#define sokoban_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct map {
	int step;
	int width;
	int height;
	int boxes_len;
	int random;
	char *file_path;
	struct cell *content;
	struct entity *boxes;
	struct entity *player;
};

struct cell {
	int id;
	int x;
	int y;
	int state;
};

struct entity {
	int id;
	int x;
	int y;
};

// main.c
char *get_file_content(const char *file_path);
void dispose(struct map *map);

// my_engine_fields.c
void push_box(struct cell requested_cell, struct cell distance_cell,
struct map *map);
void move_player(struct cell requested_cell, struct map *map);
int can_move_player(struct map *map, int index);

// my_engine_menu.c
void display_menu(struct map *map);
int key_event(struct map *map, int ch, int i);
int entry_selected_event(struct map *map, int i);
int first_display_menu(WINDOW *w);
void menu_write_highlight(WINDOW *w, int i);

// my_engine_select.c
void display_select(struct map *map);
int first_display_select(WINDOW *w);
int select_key_event(struct map *map, int ch, int i);
int select_entry_event(struct map *map, int i);
void select_write_highlight(WINDOW *w, int i);

// my_engine_utils.c
void delete_window(WINDOW *w);
void init_screen(void);
void init_menu(WINDOW *w);
void init_first_menu(WINDOW *w);

// my_engine.c
void process(struct map *map);
void event_on_key(int key, struct map *map);
struct cell get_requested_cell(int key, struct map *map, int dist);

// my_get.c
void get_help(void);
struct map *get_map_instance(void);
struct cell get_cell_instance(int id, int x, int y, int state);
struct entity get_entity(int id, int x, int y);
struct entity *get_entity_star(int id, int x, int y);

// my_map.c
void serialize_map(struct map *map, char *file_path);
void display_map(struct map *map);
void set_size_map(char *content, struct map *map);
void set_map(char *content, struct map *map);
int set_cell_map(char value);

// my_put.c
int my_put_nbr(int nb);
void my_put_str(const char *str);
void my_put_char(char c);

// my_random_entity.c
void set_random_player_placement(struct map *map);
void set_random_boxes(struct map *map);
void set_random_walls(struct map *map);
int cell_free(struct map *map, int cell, int var);
int box_free(struct map *map, int cell);

// my_random.c
void serialize_random_map(struct map *map);
void set_random_map(struct map *map);
void set_borders(struct map *map);
int crand(int a, int b);

// my_report.c
void report_error(const char *str);

// my_utils.c
void manage_entity(struct map *map, char c, struct cell cell);
int box_at_cell(struct map *map, int index);
int game_finished(struct map *map);
int box_blocked(struct map *map);
int get_block_count(struct entity box, struct map *map);

#endif /* sokoban_ */
