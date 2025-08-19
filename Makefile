NAME = cub3D

SRC = main.c mapctl.c get_next_line.c get_next_line_utils.c lstfnc.c utils.c init.c check.c

OBJS = main.o mapctl.o get_next_line.o get_next_line_utils.o lstfnc.o utils.o init.o check.o

CFLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)


clean:
	@rm -f $(OBJS)
	make clean -C libft

go: all clean

fclean: clean
	@rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re