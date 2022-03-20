#ifndef RANDOM_NUMBER_H
# define RANDOM_NUMBER_H

#include "2048.h"

void get_coordonnate_random_free_tile(int index_free_case, int *i, int *j);
void add_tile(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int calcul_number_of_free_case(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN]);
int	*create_array_of_free_case(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int array_size);
int random_tile(int *array_number, int array_size);
int	pop_number(void);

#endif