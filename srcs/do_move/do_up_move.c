/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_up_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:36:39 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 17:17:10 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "do_move.h"
#include "2048.h"
void	up_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int col;

	col = 0;
	while (col < BOARD_SIDE_LEN)
	{
		do_fusion_up(cases, col);
		reorganize_up(cases, col);
		col++;
	}
}

void	do_fusion_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line;
	int curline;
	
	line = 0;
	while (line < BOARD_SIDE_LEN - 1)
	{
		curline = line + 1;
        while (cases[curline][col].value == 0 && curline < BOARD_SIDE_LEN - 1)
            curline++;
		if (cases[line][col].value == cases[curline][col].value)
		{
			cases[line][col].value = cases[line][col].value * 2;
			cases[curline][col].value = 0;
		}
		line++;
	}
}

int	find_line_to_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line)
{
	int line_to_up;

	
	line_to_up = line + 1;
	while (line_to_up < BOARD_SIDE_LEN - 1 && cases[line_to_up][col].value == 0)
		line_to_up++;
	if (cases[line_to_up][col].value == 0)
		return (NOTHING_TO_UP);
	return (line_to_up);
}

void	reorganize_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line;
	int line_to_up;
	
	printf("col = %d\n", col);
	line = 0;
	line_to_up = NOTHING_TO_UP;
	while (line < BOARD_SIDE_LEN - 1)
	{
		if (cases[line][col].value == 0)
			line_to_up = find_line_to_up(cases, col, line);
		if (line_to_up != NOTHING_TO_UP)
		{
			cases[line][col].value = cases[line_to_up][col].value;
			cases[line_to_up][col].value = 0;
            line_to_up = NOTHING_TO_UP;
		}
		line ++;
	}
}
