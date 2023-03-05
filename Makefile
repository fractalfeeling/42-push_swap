CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

SRC = main.c \
	check_input.c cost.c ft_utils.c \
	op_push.c op_reverse_rotate.c op_rotate.c op_swap.c \
	stack_init.c stack_utils.c \
	move.c position.c \
	sort_three.c sort.c

OBJ = $(SRC: .c=.o)

all: $(OBJ) $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf R(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
