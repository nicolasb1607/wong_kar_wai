/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:06:06 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 16:06:31 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "do_move.h"

void	check_moves(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int movement)
{
	if (movement == MOVE_UP)
		check_up_move(cases);
	else if (movement == MOVE_DOWN)
		checkdown_move(cases);
	else if (movement == MOVE_LEFT)
		checkleft_move(cases);
	else if (movement == MOVE_RIGHT)
		checkright_move(cases);
}