#include "check_move.h"

int	check_fusion_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = 0;
	int curcol;
	
	while (col < BOARD_SIDE_LEN - 1)
	{
		curcol= col + 1;
        while (cases[line][curcol].value == 0 && curcol < BOARD_SIDE_LEN - 1)
            curcol++;
		if (cases[line][col].value == cases[line][curcol].value)
			return (ALLOWED_MOVE);
		col++;
	}
	return (FORBIDDEN_MOVE);
}

int	check_reorganize_left(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int line)
{
	int col = 0;
	int col_to_left = -1;

	while (col < BOARD_SIDE_LEN - 1)
	{
		if (cases[line][col].value == 0)
			col_to_left = find_col_to_left(cases, col, line);
		if (col_to_left != NOTHING_TO_LEFT)
			return (ALLOWED_MOVE);
		col++;
	}
	return (FORBIDDEN_MOVE);
}

int	check_left_move(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int	line;

	line = 0;
	while (line < BOARD_SIDE_LEN)
	{
		if (check_fusion_left(cases, line) == 1)
			return (ALLOWED_MOVE);
		if (check_reorganize_left(cases, line) == 1)
			return (ALLOWED_MOVE);
		line++;
	}
	return (FORBIDDEN_MOVE);
}