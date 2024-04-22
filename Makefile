CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf
NAME = push_swap
OBJ_DIR			= obj

SRC = 	main.c \
		utils.c

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c -o $@

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJS): $(OBJ_DIR)%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean
