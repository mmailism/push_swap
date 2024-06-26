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
	int				value;
	int				current_position;
	int				final_index;
	int				push_count;
	bool			above_median;
	bool			cheapest;
	struct l_stack	*target_number;
	struct l_stack	*last;
	struct l_stack	*next;
	struct l_stack	*prev;
}	t_stack;

typedef struct l_list
{
	// int		size_a;
	// int		size_b;
	int		max;
	int		min;
	int		mid;
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
void	swap(int *a, int *b);
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack);

//push.c
void	pa(t_list *stack);
void	pb(t_list *stack);

//rotate.c
void	ra(t_list *stack);
void	rb(t_list *stack);
void	rr(t_list *stack);

//reverse.c
void	rra(t_list *stack);
void	rrb(t_list *stack);
void	rrr(t_list *stack);

//main.c
void	print_stack(t_stack *stack, int mode);
void	error_free(t_list *stack);
bool	is_sort(t_list *ref);

//stack.c
int		stack_len(t_list *stack);
void	add_data(t_list *stack, int argc, char **argv);
t_stack	*bottom_stack(t_stack *stack);

//stack_utils.c
int		convert_nb(char *str_nbr, t_list *stack);
void	check_dup(int nb, t_list *stack);
t_stack	*alloc_stack(t_list *lst, t_stack *stack, int nb);
int		stack_size(t_list *stack, char name);
t_list	*find_last_node_a(t_list *head);

//tiny_sort.c
void	tiny_sort_3(t_list *stack);
void	tiny_sort_4(t_list *stack);

//tiny_sort_5.c
void	tiny_sort_5(t_list *stack);

//big_sort.c
void	bigsort(t_list *stack);
// int	find_mid(t_list *stack);

//big_sort_utils.c
void    more_mid(t_list *stack);

//free.c
void	free_data(t_list *stack);
char	**free_split(char **data);
void	print_stack(t_stack *stack, int mode);

//print.c
int		show_output(char *str, int show);

void	sort_many(t_list *stack, int argc);

#endif