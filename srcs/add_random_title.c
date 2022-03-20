/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_random_title.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:07:41 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 19:32:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "random_number.h"

void add_tile(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int i;
	int j;
	
	int index_free_case;
	int random_number;
	int number_of_free_case;
	int *array_number;

	number_of_free_case = calcul_number_of_free_case(cases);
	array_number = create_array_of_free_case(cases, number_of_free_case);
	if (!array_number)
		exit(EXIT_FAILURE);
	index_free_case = random_tile(array_number, number_of_free_case);
	random_number = pop_number();
	get_coordonnate_random_free_tile(index_free_case, &i, &j);
	cases[i][j].value = random_number;
}

void get_coordonnate_random_free_tile(int index_free_case, int *i, int *j)
{
	*i = index_free_case / 4;
	*j = index_free_case % 4;
}
int calcul_number_of_free_case(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN])
{
	int number_of_free_case;

	number_of_free_case = 0;
	for (int i = 0; i < BOARD_SIDE_LEN; i++)
	{
		for (int j = 0; j < BOARD_SIDE_LEN; j++)
		{
			if (cases[i][j].value == 0)
				number_of_free_case++;
		}
	}
	return (number_of_free_case);
}

int	*create_array_of_free_case(t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN], int array_size)
{
	int *array_number;
	int k = 0;
	array_number = malloc(sizeof(int) * array_size);
	if (!array_number)
		exit(EXIT_FAILURE);
	for (int i = 0; i < BOARD_SIDE_LEN; i++)
	{
		for (int j = 0; j < BOARD_SIDE_LEN; j++)
		{
			if (cases[i][j].value == 0)
			{
				array_number[k] = j + i * 4;
				k++;
			}
		}
	}
	return (array_number);
}


int random_tile(int *array_number, int array_size)
{	
	int randomIndex;
	int randomValue;

  //  srand(time(NULL));	
    randomIndex = rand() % array_size;
    randomValue = array_number[randomIndex];
    return (randomValue);
}

int	pop_number(void)
{
	int random_number;

//	srand(time(NULL));	
	random_number = rand() % 100;
	//printf("RANDOME NUMBER = %d\n", random_number);
	if (random_number >= 80)
		return (4);
	else
		return (2);
}

/*

numero de case = j + i*4 
i = 3 et j = 3
3 + 3 * 4 = 15

j = 0 - 3; [4]
i = 4 * j;

12 = 3 * i + j (j = 0);

12 / i = 3 
12 - 3 * 4 = j * 0;

i = index_free_case / 4;
j = index_free_case % 4;

*/
