/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:28:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/20 19:47:05 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void print_tab(t_window tab[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf ("%d ", tab[i][j].value);
		}
	printf("\n");
	}
	
}

int main(void)
{
	WINDOW *init_2048;
	t_window cases[BOARD_SIDE_LEN][BOARD_SIDE_LEN];
//	int key_pressed;

//	key_pressed = 0;
	if (!initscr())
		exit(1);
	curs_set(FALSE);
	init_2048 = newwin(LINES, COLS, 0, 0);
	init_board(cases, init_2048);
	while (1)
	{
		keypad(init_2048, true);
		if (terminal_size_is_ok(LINES, COLS))
		{
			init_2048 = newwin(LINES, COLS, 0, 0);
			wrefresh(init_2048);
			display_board(cases);
		}
		else
		{
			display_size_error();
		}
		//key_pressed = getch();
		sleep(100);
	}

	endwin();

	return 0;
}



// int main(void)
// {
// 	t_window tab[4][4];
// 	//t_windows tab[4][4] = {{0, 2 ,0 ,0},{0, 0 ,0 ,0}, {4, 0, 0, 0}, {0, 0, 0, 0}};

// 	tab[0][0].value = 0;
// 	tab[0][1].value = 0;
// 	tab[0][2].value = 0;
// 	tab[0][3].value = 0;

// 	tab[1][0].value = 0;
// 	tab[1][1].value = 0;
// 	tab[1][2].value = 0;
// 	tab[1][3].value = 0;

// 	tab[2][0].value = 0;
// 	tab[2][1].value = 0;
// 	tab[2][2].value = 0;
// 	tab[2][3].value = 0;

// 	tab[3][0].value = 0;
// 	tab[3][1].value = 0;
// 	tab[3][2].value = 0;
// 	tab[3][3].value = 0;


// 	srand(time(NULL));
// 	add_tile(tab);
// 	usleep(30);
// 	add_tile(tab);
// 	printf("ORIGINAL:\n");
// 	print_tab(tab);
// 	printf("---------------------------------------------\n");
/*
	printf("MOVE_RIGHT:\n");
	move_tiles(tab, MOVE_RIGHT);
	print_tab(tab);
	printf("---------------------------------------------\n");
	
	printf("MOVE_LEFT:\n");
	move_tiles(tab, MOVE_LEFT);
	print_tab(tab);
	printf("---------------------------------------------\n");

	printf("MOVE LEFT:\n");
	move_tiles(tab, MOVE_LEFT);
	print_tab(tab);
	printf("---------------------------------------------\n");

	printf("MOVE_UP:\n");
	move_tiles(tab, MOVE_UP);
	print_tab(tab);
	printf("---------------------------------------------\n");
	
	printf("MOVE_UP:\n");
	move_tiles(tab, MOVE_UP);
	print_tab(tab);
	printf("---------------------------------------------\n");

	printf("MOVE_DOWN:\n");
	move_tiles(tab, MOVE_DOWN);
	print_tab(tab);
	printf("---------------------------------------------\n");
	
	printf("MOVE_RIGHT:\n");
	move_tiles(tab, MOVE_RIGHT);
	print_tab(tab);
	printf("---------------------------------------------\n");
	
	printf("MOVE_RIGHT:\n");
	move_tiles(tab, MOVE_RIGHT);
	print_tab(tab);
	printf("---------------------------------------------\n");
	
	printf("MOVE_UP:\n");
	move_tiles(tab, MOVE_UP);
	print_tab(tab);
	printf("---------------------------------------------\n");

	printf("MOVE_LEFT:\n");
	move_tiles(tab, MOVE_LEFT);
	print_tab(tab);
	printf("---------------------------------------------\n");

}
*/