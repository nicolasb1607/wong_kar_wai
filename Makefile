CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
EXEC = 2048
SRCS = ./main.c \
	./srcs/init.c \
	./srcs/ft_itoa.c \
	./srcs/add_random_title.c \
	./srcs/check_end_game.c \
	./srcs/check_move/check_down_move.c \
	./srcs/check_move/check_up_move.c \
	./srcs/check_move/check_left_move.c \
	./srcs/check_move/check_right_move.c \
	./srcs/do_move/do_move.c \
	./srcs/do_move/do_down_move.c \
	./srcs/do_move/do_up_move.c \
	./srcs/do_move/do_left_move.c \
	./srcs/do_move/do_right_move.c \

OBJS =${SRCS:.c=.o}

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(EXEC) -lncurses -I $(INCLUDES) 

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@ -lncurses -I $(INCLUDES) 

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean all

.PHONY : all clean fclean re