/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:31:59 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 15:35:21 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_move.h"

void	move_tiles(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int movement)
{
	if (movement == MOVE_UP)
		up_move(cases);
	else if (movement == MOVE_DOWN)
		down_move(cases);
	else if (movement == MOVE_LEFT)
		left_move(cases);
	else if (movement == MOVE_RIGHT)
		right_move(cases);
}