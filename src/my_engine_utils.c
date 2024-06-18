/*
** EPITECH PROJECT, 2017
** my_engine_utils.c
** File description:
**
*/

#include "sokoban.h"

void init_first_menu(WINDOW *w)
{
	initscr();
	box(w, 0, 0);
}

void init_menu(WINDOW *w)
{
	wrefresh(w);
	noecho();
	keypad(w, TRUE);
	curs_set(0);
}

void init_screen(void)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}

void delete_window(WINDOW *w)
{
	if (w != NULL)
		delwin(w);
	endwin();
}