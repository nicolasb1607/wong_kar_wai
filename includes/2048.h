#ifndef G2048_H
# define G2048_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct s_window
{
    int value;
    int height;
	int width;
	WINDOW *ptr;
} t_window;


/* ----- main.c ----- */



#endif