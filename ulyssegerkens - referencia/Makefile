# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 14:02:06 by ugerkens          #+#    #+#              #
#    Updated: 2024/09/04 13:21:56 by antonimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc -I. -O3
RM					=	rm -rf
PUSH_SWAP			=	push_swap
NAME				=	$(PUSH_SWAP)

# Libraries
LIBFT				=	libft.a
LIBFT_DIR			=	lib/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

FT_PRINTF			=	ft_printf.a
FT_PRINTF_DIR		=	lib/ft_printf
FT_PRINTF_FILE		=	$(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
VPATH				=	src:src/stack:src/push_swap:src/checker_bonus:include
STACK_INC			=	stack.h
STACK_SRC			=	data_mngt.c stack_init.c stack_utils.c op_push.c \
                        op_reverse_rotate.c op_rotate.c op_swap.c op_utils.c
PUSH_SWAP_INC		=	$(STACK_INC) push_swap.h
PUSH_SWAP_SRC		=	$(STACK_SRC) push_swap.c sort.c move.c chunk_sort.c  \
                        chunk_split.c chunk_utils.c \
                        opti_to_the_top.c \

# Object Files
OBJ_DIR				=	obj
PUSH_SWAP_OBJ		=	$(addprefix $(OBJ_DIR)/, $(PUSH_SWAP_SRC:.c=.o))

# Rules
all: $(NAME)

$(LIBFT_FILE):
	$(MAKE_LIB) $(LIBFT_DIR)

$(FT_PRINTF_FILE):
	$(MAKE_LIB) $(FT_PRINTF_DIR)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(LIBFT_FILE) $(FT_PRINTF_FILE)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -L $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE_LIB) $(LIBFT_DIR) clean
	$(MAKE_LIB) $(FT_PRINTF_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE_LIB) $(LIBFT_DIR) fclean
	$(MAKE_LIB) $(FT_PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re