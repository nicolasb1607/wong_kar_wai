#include "check_move.h"

int	check_fusion_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = BOARD_SIDE_LEN;
	int curcol;
	
	while (col > 0)
	{
		curcol= col - 1;
        while (cases[line][curcol].value == 0)
            curcol--;
		if (cases[line][col].value == cases[line][curcol].value)
			return (ALLOWED_MOVE);
		col--;
	}
	return (FORBIDDEN_MOVE);
}

int	check_reorganize_right(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = BOARD_SIDE_LEN;
	int col_to_right = -1;

	while (col > 0)
	{
		if (cases[line][col].value == 0)
			col_to_right = find_col_to_right(cases, col, line);
		if (col_to_right != NOTHING_TO_RIGHT)
			return (ALLOWED_MOVE);
		col--;
	}
	return (FORBIDDEN_MOVE);
}

int	check_right_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int	line;

	line = 0;
	while (line < BOARD_SIDE_LEN)
	{
		if (check_fusion_right(cases, line) == 1)
			return (ALLOWED_MOVE);
		if (check_reorganize_right(cases, line) == 1)
			return (ALLOWED_MOVE);
		line++;
	}
	return (FORBIDDEN_MOVE);
}