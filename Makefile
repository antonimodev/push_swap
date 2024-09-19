# Variables #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -g #-Werror
RM		= rm -rf

# Libraries #

LIBFT_DIR		= lib/libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR	= lib/printf
FT_PRINTF_FILE	= $(FT_PRINTF_DIR)/ft_printf.a

MAKE_LIB		= make --no-print-directory -C
MAKE_LIB_BONUS	= make bonus --no-print-directory -C

# Push swap sources #

PUSH_SWAP_SRC	= push_swap.c \
init_stacks.c stack_utils.c error.c split_check.c \
sort.c sort_utils.c \
chunk_sort.c chunk_split.c chunk_utils.c \
move.c chunk_optimization.c \
op_push.c op_reverse_rotate.c op_rotate.c op_swap.c \
print_operations.c

# Push swap objects #

PUSH_SWAP_OBJ = $(addprefix obj/, $(PUSH_SWAP_SRC:.c=.o))

# Rules #

all: $(NAME)

$(LIBFT_FILE):
	@$(MAKE_LIB_BONUS) $(LIBFT_DIR)

$(FT_PRINTF_FILE):
	@$(MAKE_LIB) $(FT_PRINTF_DIR)

obj/%.o:%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJ) $(LIBFT_FILE) $(FT_PRINTF_FILE)
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -L $(FT_PRINTF_DIR)
	@echo $(NAME) compiled!

clean:
	@$(RM) obj
	@$(RM) $(LIBFT_DIR)/*.o
	@$(RM) $(FT_PRINTF_DIR)/*.o
	@echo Objects removed

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_FILE)
	@$(RM) $(FT_PRINTF_FILE)
	@echo Executable removed

re: fclean all

.PHONY: all clean fclean re