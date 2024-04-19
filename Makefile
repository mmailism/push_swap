CC = cc
CFLAGS = -Wall -Wextra -Werror -I/push_swap.h
# LIBFT = ./libft/libft.a
RM = rm -rf
NAME = push_swap

SRC = 	push_swap.c / utils.c / stack.c

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) $(CC) $(CFLAGS) $(OBJS) -o push_swap

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
		$(MAKE) clean
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean
		$(RM) $(NAME)

re: fclean all

run: all clean

.PHONY: all clean