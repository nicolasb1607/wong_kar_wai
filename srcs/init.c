/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:20:03 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/20 19:49:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void print_centered(WINDOW *win, int start_row, char *str)
{
	int center_col = win->_maxx / 2;
	int half_length = strlen(str) / 2;
	int adjusted_col = center_col - half_length;

	mvwprintw(win, start_row, adjusted_col, str);
}

int terminal_size_is_ok(int terminal_lines, int terminal_cols)
{
	if (terminal_lines >= BOARD_HEIGHT && terminal_cols >= BOARD_WIDTH)
		return (1);
	else
		return (0);
}

void display_size_error(void)
{
	WINDOW *win;
	
	win = newwin(LINES, COLS, 0, 0);
	wprintw(win, "too small LINES = %d COLS = %d\n", LINES, COLS);
	wgetch(win);
}

WINDOW *create_subwin(WINDOW *init, int height, int width)
{
	WINDOW *win;

	int top_left_corner_height = (LINES - BOARD_HEIGHT) / 2 + (BOARD_HEIGHT / BOARD_SIDE_LEN) * height;
	int top_left_corner_width = (COLS - BOARD_WIDTH) / 2 + (BOARD_WIDTH / BOARD_SIDE_LEN) * width;

	win = subwin(init, BOARD_HEIGHT / BOARD_SIDE_LEN, BOARD_WIDTH / BOARD_SIDE_LEN, top_left_corner_height, top_left_corner_width);
	box(win, 0, 0);
	return (win);
}

void init_board(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], WINDOW *init)
{
	int height = 0;
	int width = 0;

	while (height < BOARD_SIDE_LEN)
	{
		width = 0;
		while (width < BOARD_SIDE_LEN)
		{
			cases[height][width].value = 0;
			cases[height][width].ptr = create_subwin(init, height, width);
			width++;
		}
		height++;
	}
	add_tile(cases);
	add_tile(cases);
}

void	display_board(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int height = 0;
	int width = 0;
	
	while (height < BOARD_SIDE_LEN)
	{
		width = 0;
		while (width < BOARD_SIDE_LEN)
		{
			if (cases[height][width].value != 0)
				print_centered(cases[height][width].ptr, height, ft_itoa(cases[height][width].value));
			wrefresh(cases[height][width].ptr);
			width++;
		}
		height++;
	}
}