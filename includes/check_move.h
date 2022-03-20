/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:46:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 15:47:46 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MOVE_H
#define CHECK_MOVE_H

# include "2048.h"

# define NOTHING_TO_UP -1
# define NOTHING_TO_DOWN -1
# define NOTHING_TO_LEFT -1
# define NOTHING_TO_RIGHT -1

# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_RIGHT 2
# define MOVE_LEFT 3

# define FORBIDDEN_MOVE 0
# define ALLOWED_MOVE 1


//------------ check_moves.c -------------

void	check_moves(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int movement);

//-------------UP--------------

int	check_up_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int	check_fusion_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);
int	check_reorganize_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);

//-------------DOWN--------------

int	check_down_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int	check_fusion_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);
int	check_reorganize_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);

//-------------LEFT--------------

int	check_fusion_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
int	check_reorganize_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
int	check_left_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);

//-------------RIGHT--------------

int	check_fusion_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
int	check_reorganize_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
int	check_right_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);


#endif