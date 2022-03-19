/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:20:03 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/19 21:05:16 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

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
			cases[height][width].ptr = create_subwin(init, height, width);
			width++;
		}
		height++;
	}
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
			wrefresh(cases[height][width].ptr);
			width++;
		}
		height++;
	}
}