/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_game.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:13:49 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 15:45:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_END_GAME_H
#define CHECK_END_GAME_H

# include "2048.h"

int	horizontal_move_possible(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int	vertical_move_possible(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int	empty_case_available(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int	check_possible_moves(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);

#endif