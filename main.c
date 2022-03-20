/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:28:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/20 16:44:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void print_centered(WINDOW *win, int start_row, char *str)
{
	int center_col = win->_maxx / 2;
	int half_length = strlen(str) / 2;
	int adjusted_col = center_col - half_length;

	mvwprintw(win, start_row, adjusted_col, str);
}

void print_tab(t_window tab[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf ("%d ", tab[i][j].value);
		}
	printf("\n");
	}
	
}

int main(void)
{
	t_window tab[4][4];
	//t_windows tab[4][4] = {{0, 2 ,0 ,0},{0, 0 ,0 ,0}, {4, 0, 0, 0}, {0, 0, 0, 0}};
	tab[0][0].value = 4;
	tab[0][1].value = 2;
	tab[0][2].value = 4;
	tab[0][3].value = 2;

	tab[1][0].value = 4;
	tab[1][1].value = 2;
	tab[1][2].value = 0;
	tab[1][3].value = 0;

	tab[2][0].value = 4;
	tab[2][1].value = 0;
	tab[2][2].value = 0;
	tab[2][3].value = 0;

	tab[3][0].value = 4;
	tab[3][1].value = 0;
	tab[3][2].value = 0;
	tab[3][3].value = 0;

	print_tab(tab);
	printf("---------------------------------------------\n");
	move_tiles(tab, MOVE_UP);
	
/*	print_tab(tab);
	move_tiles(tab, MOVE_UP);
	printf("---------------------------------------------\n");
	print_tab(tab);
*/
}

/*
int main(void)
{
	WINDOW *init_2048;
	t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN];

	if (!initscr())
		exit(1);
	curs_set(false);
	while (1)
	{
		init_2048 = newwin(LINES, COLS, 0, 0);
		//		wprintw(init_2048, "LINES = %d COLS = %d\n", LINES, COLS);
		wrefresh(init_2048);
		if (terminal_size_is_ok(LINES, COLS))
		{
			init_board(cases, init_2048);
			display_board(cases);
		}
		else
		{
			display_size_error();
		}
		sleep(100);
	}

	endwin();

	return 0;
}
*/