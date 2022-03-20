#include "do_move.h"

void	do_fusion_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = BOARD_SIDE_LEN;
	int curcol;
	
	while (col > 0)
	{
		curcol= col - 1;
        while (cases[line][curcol].value == 0)
            curcol--;
		if (cases[line][col].value == cases[line][curcol].value)
		{
			cases[line][col].value = cases[line][col].value * 2;
			cases[line][curcol].value = 0;
		}
		col--;
	}
}

int	find_col_to_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line)
{
	int col_to_right;

	col_to_right = col - 1;
	while (col_to_right > 0 && cases[line][col_to_right].value == 0)
		col_to_right--;
	if (cases[line][col_to_right].value == 0)
		return (NOTHING_TO_RIGHT);
	return (col_to_right);
}

void	reorganize_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = BOARD_SIDE_LEN;
	int col_to_right = -1;

	while (col > 0)
	{
		if (cases[line][col].value == 0)
			col_to_right = find_col_to_right(cases, col, line);
		if (col_to_right != NOTHING_TO_RIGHT)
		{
			cases[line][col].value = cases[line][col_to_right].value;
			cases[line][col_to_right].value = 0;
			col_to_right = NOTHING_TO_RIGHT;
		}
		col--;
	}
}

void	right_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int	line;

	line = 0;
	while (line < BOARD_SIDE_LEN)
	{
		do_fusion_right(cases, line);
		reorganize_right(cases, line);
		line++;
	}
}