CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.c \
	check_input.c cost.c ft_utils.c \
	op_push.c op_reverse_rotate.c op_rotate.c op_swap.c \
	stack_init.c stack_utils.c \
	move.c position.c \
	sort_three.c sort.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCS = -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
