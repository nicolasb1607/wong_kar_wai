/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_down_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:52:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 17:04:08 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_move.h"

void	down_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int col;

	col = 0;
	while (col < BOARD_SIDE_LEN)
	{
		do_fusion_down(cases, col);
		reorganize_down(cases, col);
		col++;
	}
}

void	do_fusion_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line;
	int curline;
	
    line = BOARD_SIDE_LEN - 1;
	while (line > 0)
	{
		curline = line - 1;
        while (cases[curline][col].value == 0 && curline >= 0)
            curline--;
		if (cases[line][col].value == cases[curline][col].value)
		{
			cases[line][col].value = cases[line][col].value * 2;
			cases[curline][col].value = 0;
		}
		line--;
	}
}

int	find_line_to_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line)
{
	int line_to_down;

	line_to_down = line - 1;
	while (line_to_down > 0 && cases[line_to_down][col].value == 0)
		line_to_down--;
	if (cases[line_to_down][col].value == 0)
		return (NOTHING_TO_DOWN);
	return (line_to_down);
}

void	reorganize_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line;
	int line_to_down;

    line = BOARD_SIDE_LEN - 1;
	line_to_down = NOTHING_TO_DOWN;
	while (line > 0)
	{
		if (cases[line][col].value == 0)
			line_to_down = find_line_to_down(cases, col, line);
		if (line_to_down != NOTHING_TO_DOWN)
		{
			cases[line][col].value = cases[line_to_down][col].value;
			cases[line_to_down][col].value = 0;
            line_to_down = NOTHING_TO_DOWN;
		}
		line--;
	}
}
