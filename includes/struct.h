#ifndef STRUCT_H
# define STRUCT_H

# include "2048.h"

#define BOARD_HEIGHT 40
#define BOARD_WIDTH BOARD_HEIGHT * 2

#define BOARD_SIDE_LEN 4

typedef struct s_window
{
    int value;
    int height;
	int width;
	WINDOW *ptr;
} 	t_window;

#endif