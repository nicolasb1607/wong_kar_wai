/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_up_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:36:39 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 16:53:40 by rpottier         ###   ########.fr       */
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
//		printf("TEMOIN 0\n");
		
		do_fusion_up(cases, col);
		printf("AFTER FUSION\n");
		print_tab(cases);
		printf("---------------------------------------------\n");
//		printf("TEMOIN 1\n");
		reorganize_up(cases, col);
		printf("AFTER reorganize\n");
		print_tab(cases);
		printf("---------------------------------------------\n");
//		printf("TEMOIN 2\n");
		col++;
	}
}

void	do_fusion_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line = 0;
	int curline;
	
	while (line < BOARD_SIDE_LEN - 1)
	{
		curline = line + 1;
        while (curline < BOARD_SIDE_LEN && cases[curline][col].value == 0)
            curline++;
		if (cases[line][col].value == cases[curline][col].value)
		{
			cases[line][col].value = cases[line][col].value * 2;
			cases[curline][col].value = 0;
		}
		line ++;
	}
}

int	find_line_to_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line)
{
	int line_to_up;

	line_to_up = line + 1;
	while (line_to_up < BOARD_SIDE_LEN && cases[line_to_up][col].value == 0)
		line_to_up++;
	if (cases[line_to_up][col].value == 0)
		return (NOTHING_TO_UP);
	return (line_to_up);
}
/*
8
0
8
0
line = 1
line_to_up =  -1
*/
void	reorganize_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line = 0;
	int line_to_up;

	line_to_up = NOTHING_TO_UP;
	while (line < BOARD_SIDE_LEN - 1)
	{
		if (cases[line][col].value == 0)
			line_to_up = find_line_to_up(cases, col, line);
		if (line_to_up != NOTHING_TO_UP)
		{
			cases[line][col].value = cases[line_to_up][col].value;
			cases[line_to_up][col].value = 0;
	//		printf("\n\n cases[line_to_up][col].value", line_to_up], col)
            line_to_up = NOTHING_TO_UP;
		}
		line ++;
	}
}
