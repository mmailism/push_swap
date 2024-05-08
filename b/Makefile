NAME 			= push_swap
CC 				= gcc
CFLAGS			= -Wall -Werror -Wextra -Iinclude -Ilibft
LIBFT_DIR		= libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a
SRC_DIR			= src
OBJ_DIR			= obj

VPATH = $(SRC_DIR)

PUSH_SWAP_SRC	=	main.c \
					utils.c \
					utils_in_utils.c \
					push.c \
					reverse.c \
					rotate.c \
					swap.c \
					free.c \
					stack.c \
					stack_utils.c \
					sort_3.c \
					tiny_sort_5.c \
					tiny_sort_5_utils.c \
					big_sort.c \
					big_sort_utils.c

PUSH_SWAP_OBJ	=	$(PUSH_SWAP_SRC:%.c=obj/%.o)

$(NAME): $(LIBFT_FILE) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT_FILE) -o $@

$(LIBFT_FILE):
	$(MAKE) -C $(LIBFT_DIR)

$(PUSH_SWAP_OBJ): $(OBJ_DIR)/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
