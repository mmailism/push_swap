CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/push_swap.h
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = push_swap

SRC = 	push_swap.c

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

run: all clean

.PHONY: all clean