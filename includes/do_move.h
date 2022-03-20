/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:38:01 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 16:31:35 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_MOVES_H
#define DO_MOVE_H

# define NOTHING_TO_UP -1
# define NOTHING_TO_DOWN -1
# define NOTHING_TO_LEFT -1
# define NOTHING_TO_RIGHT -1

# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_RIGHT 2
# define MOVE_LEFT 3

# include "2048.h"

//------------------ do_move.c -------------------

void	move_tiles(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int movement);

//-------------------UP--------------------
void	up_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
void	do_fusion_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);
int		find_line_to_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line);
void	reorganize_up(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);
//-------------------DOWN--------------------
void	down_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
void	do_fusion_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);
int		find_line_to_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line);
void	reorganize_down(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col);
//-------------------LEFT--------------------
void	do_fusion_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
int		find_col_to_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line);
void	reorganize_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
void	left_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
//-------------------RIGHT--------------------
void	do_fusion_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
int		find_col_to_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line);
void	reorganize_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line);
void	right_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);



#endif