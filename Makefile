# Variables #
NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# Libraries #

LIBFT		= libft.a
LIBFT_DIR	= #ruta del libft

FT_PRINTF	= ft_printf.a
FT_PRINTF	= #ruta de ft_printf

# Push swap sources #

PUSH_SWAP_SRC	= init_stacks.c stack_utils.c error.c \
sort.c sort_utils.c \
chunk_sort.c chunk_split.c chunk_utils.c \
move.c chunk_optimization.c \
op_push.c op_reverse_rotate.c op_rotate.c op_swap.c \
print_operations.c

# Push swap objects #

OBJ_DIR = push_swap_obj
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR)/, $(PUSH_SWAP_SRC:.c=.o))

# Rules #

all:

clean:

fclean: clean

re: fclean all

.PHONY: all clean fclean re