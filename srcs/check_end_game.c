/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:12:02 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 16:23:19 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ici on checke quand le board est remplie de tuile*/

#include "check_move.h"

int	horizontal_move_possible(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	
	while (height < BOARD_SIDE_LEN - 1)
	{
		width = 0;
		while (width < BOARD_SIDE_LEN - 1)
		{
			if (cases[height][width].value == cases[height][width + 1].value)
				return (1);
			width++;
		}
		height++;
	}
	return (0);
}

int	vertical_move_possible(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int line = 0;
	int col = 0;

	while (col < BOARD_SIDE_LEN)
	{
		line = 0;
		while (line < BOARD_SIDE_LEN)
		{
			if (cases[line][col].value == cases[line + 1][col].value)
				return (1);
			line++;
		}
		col++;
	}
	return (0);
}


int	empty_case_available(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int	i = 0;
	int	j = 0;

	while (i < BOARD_SIDE_LEN)
	{
		j = 0;
		while (j < BOARD_SIDE_LEN)
		{
			if (cases[i][j].value == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_possible_moves(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	if (empty_case_available(cases) == 0)
	{
		if (horizontal_move_possible(cases))
			return (1);
		else if (vertical_move_possible(cases))
			return (1);
		else 
			return (0);
	}
	return (0);
}