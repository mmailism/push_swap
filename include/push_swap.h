#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
// # include "./libft/libft.h"
# include <stdio.h>

typedef struct l_stack
{
	int				nb;
	int				sort;
	struct l_stack	*last;
	struct l_stack	*next;
	struct l_stack	*prev;
}	t_stack;

typedef struct l_list
{
	int		size_a;
	int		size_b;
	int		show_output;
	t_stack	*a;
	t_stack	*b;
	t_stack	*top_a;
	t_stack	*bottom_a;
	t_stack	*top_b;
	t_stack	*bottom_b;
	t_stack	*tmp;
}	t_list;

// t_stack	*stack_add(t_stack *stack, t_stack *new);
// t_stack	*stack_init(t_stack *a, t_stack *new);
// t_stack	*stack_last(t_stack *lst);
// t_stack *stack_new(int *new);
// t_stack	get_numbers(char *av, t_stack *stack_a);

char	**ft_split(char const *s, char c);

//swap.c
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack);

//push.c
void	pa(t_list *stack);

//main.c
void print_stack(t_stack *stack, int mode);

//free.c
void	error_free(t_list *stack);
void	free_data(t_list *stack);
char	**free_split(char **data);

#endif