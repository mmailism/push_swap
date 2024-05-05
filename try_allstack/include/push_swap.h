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

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int	atoi_pushswap(const char *str);

char	**ft_split(char const *s, char c);

//swap.c
void	sb(t_stack **stack_b, int j);
void	sa(t_stack **stack_a, int j);
void	ss(t_stack **stack_a, t_stack **stack_b, int j);

//push.c
void	pa(t_stack **stack_a, t_stack **stack_b, int j);
void	pb(t_stack **stack_a, t_stack **stack_b, int j);

//rotate.c
void	ra(t_stack **stack_a, int j);
void	rb(t_stack **stack_b, int j);
void	rr(t_stack **stack_a, t_stack **stack_b, int j);

//reverse.c
void	rra(t_stack **stack_a, int j);
void	rrb(t_stack **stack_b, int j);
void	rrr(t_stack **stack_a, t_stack **stack_b, int j);

//main.c
void	print_stack(t_stack **stack, int mode);
void	error_free(t_stack *stack);
int		is_sort(t_stack *stack_a);

//stack.c
void	stack_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*stack_new(int content);
t_stack	*ft_lstlast(t_stack *lst);
int	stack_size(t_stack *lst);

//stack_utils.c
// int		stack_size(t_stack *stack, char name);
// t_stack	*find_last_node_a(t_stack *head);

//tiny_sort.c
void	tiny_sort_3(t_stack **stack_a);
void	tiny_sort_4(t_stack **stack_a, t_stack **stack_b);

//tiny_sort_5.c
void	tiny_sort_5(t_stack **stack_a, t_stack **stack_b);

//big_sort.c
void	push_swap(t_stack **stack_a);
// void	bigsort(t_stack *stack);
// int	find_mid(t_stack *stack);

//big_sort_utils.c
// void    more_mid(t_stack *stack);

//free.c
void	free_data(t_stack *stack);
void	free_stack(t_stack *stack);
// char	**free_split(char **data);
// void	print_stack(t_stack *stack, int mode);

#endif