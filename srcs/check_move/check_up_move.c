/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:46:31 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 17:36:30 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_move.h"

int	check_up_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int col;

	col = 0;
	while (col < BOARD_SIDE_LEN)
	{
		if (check_fusion_up(cases, col) == ALLOWED_MOVE)
            return (ALLOWED_MOVE);
		if (check_reorganize_up(cases, col) == ALLOWED_MOVE)
            return (ALLOWED_MOVE);
		col++;
	}
    return (FORBIDDEN_MOVE);
}

int	check_fusion_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line = 0;
	int curline;
	
	while (line < BOARD_SIDE_LEN - 1)
	{
		curline = line + 1;
        while (cases[curline][col].value == 0 && curline < BOARD_SIDE_LEN - 1)
            curline++;
		if (cases[line][col].value == cases[curline][col].value)
            return (ALLOWED_MOVE);
		line++;
	}
    return (FORBIDDEN_MOVE);
}

int	check_reorganize_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col)
{
	int line = 0;
	int line_to_up;

	line_to_up = NOTHING_TO_UP;
	while (line < BOARD_SIDE_LEN - 1)
	{
		if (cases[line][col].value == 0)
			line_to_up = find_line_to_up(cases, col, line);
		if (line_to_up != NOTHING_TO_UP)
			return (ALLOWED_MOVE);
		line++;
	}
    return (FORBIDDEN_MOVE);
}
