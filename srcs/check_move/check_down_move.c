/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_down_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:52:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 16:26:04 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_move.h"

int	check_down_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int col;

	col = 0;
	while (col < BOARD_SIDE_LEN)
	{
		if (check_fusion_down(cases, col) == ALLOWED_MOVE)
            return (ALLOWED_MOVE);
		if (check_reorganize_down(cases, col) == ALLOWED_MOVE)
            return (ALLOWED_MOVE);
		col++;
	}
	return (FORBIDDEN_MOVE);
}

int	check_fusion_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line;
	int curline;
	
    line = BOARD_SIDE_LEN - 1;
	while (line > 0)
	{
		curline = line - 1;
        while (cases[curline][col].value == 0)
            curline--;
		if (cases[line][col].value == cases[curline][col].value)
			return (ALLOWED_MOVE);
		line--;
	}
    return (FORBIDDEN_MOVE);
}

int	check_reorganize_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
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
			return (ALLOWED_MOVE);
		line--;
	}
    return (FORBIDDEN_MOVE);
}
