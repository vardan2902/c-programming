NAME    =   do-op
CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
SRCS    =   main.c \
            op_utils.c \
            operations.c
OBJS    =   $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
