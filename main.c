/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:28:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/20 17:48:24 by rpottier         ###   ########.fr       */
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
	WINDOW *init_2048;
	t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN];
//	int key_pressed;

//	key_pressed = 0;
	if (!initscr())
		exit(1);
	curs_set(FALSE);
	
	while (1)
	{
		init_2048 = newwin(LINES, COLS, 0, 0);
//		keypad(init_2048, TRUE);
		wrefresh(init_2048);
//		key_pressed = wgetch(init_2048);
//		if (key_pressed)
//			printf("key_pressed = %d\n", key_pressed);
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
