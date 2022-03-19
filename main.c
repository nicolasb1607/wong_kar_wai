/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:28:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/19 17:43:37 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/2048.h"

void print_centered(WINDOW *win, int start_row, char *str)
{
	int center_col = win->_maxx / 2;
	int half_length = strlen(str) / 2;
	int adjusted_col = center_col - half_length;

	mvwprintw(win, start_row, adjusted_col, str);
}

int	terminal_size_is_ok(int terminal_lines, int terminal_cols)
{
	if (terminal_lines >= 20 && terminal_cols >= 50)
		return (1);
	else
		return (0);
}


void	create_subwin(t_window *main, t_window *sub, int height, int width)
{
	sub->height = height;
	sub->width = width;
	sub->ptr = subwin(main->ptr, sub->height, sub->width, (LINES - sub->height) / 2, (COLS - sub->width) / 2);
	box(sub->ptr, 0, 0);
//	print_centered(sub, sub->height / 2, "  hello!");
	wgetch(sub->ptr);
}

void	display_size_error(t_window *win)
{
	win->ptr = newwin(LINES, COLS, 0, 0);
	wprintw(win->ptr, "too small LINES = %d COLS = %d\n", LINES, COLS);
	wgetch(win->ptr);
}

int main(void)
{
	int height = 20;
	int width = 40;
	t_window *init_2048;
	t_window *sub;
	
	init_2048= malloc(sizeof(t_window));
	if(!init_2048)
		return (0);
	if (!initscr())
		return (0);
	curs_set(false);
	while (1)
	{
		init_2048->ptr = newwin(LINES, COLS, 0, 0);
		wprintw(init_2048->ptr, "LINES = %d COLS = %d\n", LINES, COLS);
		wrefresh(init_2048->ptr);
		if (terminal_size_is_ok(LINES, COLS))
		{
			sub = malloc(sizeof(t_window));
			if(!sub)
				return(0);
			create_subwin(init_2048, sub, height, width);
		}
		else
		{
			init_2048->ptr = newwin(LINES, COLS, 0, 0);
			wprintw(init_2048->ptr, "too small LINES = %d COLS = %d\n", LINES, COLS);
			wgetch(init_2048->ptr);
		}
		sleep(400);
	}

	endwin();

	return 0;
}
