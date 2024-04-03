CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I push_swap.h
LIBFT = ./
RM = rm -rf
NAME = push_swap

SRC = push_swap.c 

OBJS = $(SRC:%.c=.o)

all: $(NAME)

$(all): $(OBJS)
		$(MAKE) -C ./libft $(CC) $ (CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean: 
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

run: all clean

.PHONY: all clean