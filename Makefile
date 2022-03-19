CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
EXEC = 2048
SRCS = ./main.c \
	./srcs/init.c \

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