#include "do_move.h"

void	do_fusion_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = 0;
	int curcol;
	
	while (col < BOARD_SIDE_LEN - 1)
	{
		curcol= col + 1;
        while (cases[line][curcol].value == 0)
            curcol++;
		if (cases[line][col].value == cases[line][curcol].value)
		{
			cases[line][col].value = cases[line][col].value * 2;
			cases[line][curcol].value = 0;
		}
		col++;
	}
}

int	find_col_to_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int col, int line)
{
	int col_to_left;

	col_to_left = col + 1;
	while (col_to_left < BOARD_SIDE_LEN -1 && cases[line][col_to_left].value == 0)
		col_to_left++;
	if (cases[line][col_to_left].value == 0)
		return (NOTHING_TO_LEFT);
	return (col_to_left);
}

void	reorganize_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = 0;
	int col_to_left = -1;

	while (col < BOARD_SIDE_LEN - 1)
	{
		if (cases[line][col].value == 0)
			col_to_left = find_col_to_left(cases, col, line);
		if (col_to_left != NOTHING_TO_LEFT)
		{
			cases[line][col].value = cases[line][col_to_left].value;
			cases[line][col_to_left].value = 0;
			col_to_left = NOTHING_TO_LEFT;
		}
		col++;
	}
}

void	left_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int	line;

	line = 0;
	while (line < BOARD_SIDE_LEN)
	{
		do_fusion_left(cases, line);
		reorganize_left(cases, line);
		line++;
	}
}