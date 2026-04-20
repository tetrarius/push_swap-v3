NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src
INC_DIR     = inc
OBJ_DIR     = obj

SRC_FILES   = main.c parse.c stack_utils.c disorder.c \
              operations_push.c operations_swap.c \
              operations_rot.c operations_rev.c \
              strategy_simple.c strategy_medium.c \
              strategy_complex.c strategy_adaptive.c \
              benchmark.c utils.c split.c

SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INC         = -I$(INC_DIR)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
