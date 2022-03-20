#ifndef H2048_H
# define H2048_H

# include <ncurses.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include "struct.h"
# include "init.h"
# include "random_number.h"
# include "do_move.h"
# include "check_end_game.h"
# include "check_move.h"

void print_tab(t_window tab[4][4]);
/* ----- main.c ----- */
/*
int	tile_is_empty(int number)
{
	if (number == 0)
		return (1);
	else
		return (0);
}
*/
#endif