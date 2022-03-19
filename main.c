/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:28:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/19 21:01:28 by nburat-d         ###   ########.fr       */
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