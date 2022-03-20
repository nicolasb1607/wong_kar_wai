/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_random_title.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:07:41 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/20 16:30:23 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "random_number.h"

int random_number(int *array_number, int array_size)
{	
	int randomIndex;
	int randomValue;

    srand(time(NULL));	
    randomIndex = rand() % array_size;
    randomValue = array_number[randomIndex];
    return (randomValue);
}

int	pop_number(void)
{
	int random_number;

	srand(time(NULL));	
	random_number = rand() % 100;
	//printf("RANDOME NUMBER = %d\n", random_number);
	if (random_number >= 70)
		return (4);
	else
		return (2);
}
