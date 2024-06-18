/*
** EPITECH PROJECT, 2017
** my_report.c
** File description:
**
*/

#include "sokoban.h"

void check_file(FILE *file)
{
	const char *error_file = "Fatal error: can't open file.\n";

	if (!file)
		report_error(error_file);
}

void report_error(const char *str)
{
	int len = 0;

	for (len = 0; str[len]; len++);
	write(2, str, len);
	exit(84);
}