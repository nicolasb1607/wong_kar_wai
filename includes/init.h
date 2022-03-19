#ifndef INIT_H
# define INIT_H

# include "2048.h"

int		terminal_size_is_ok(int terminal_lines, int terminal_cols);
WINDOW	*create_subwin(WINDOW *init, int height, int width);
void	init_board(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], WINDOW *init);
void	display_board(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
void	display_size_error(void);

#endif