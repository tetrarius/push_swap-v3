NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iinc

SRC     = src/main.c src/parse.c src/stack_utils.c src/disorder.c \
          src/operations_push.c src/operations_swap.c \
          src/operations_rot.c src/operations_rev.c \
          src/strategy_simple.c src/strategy_medium.c \
          src/strategy_complex.c src/strategy_adaptive.c \
          src/benchmark.c src/utils.c src/split.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
