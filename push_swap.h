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

// typedef struct s_stack
// {
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// 	struct s_stack	*target_node;
// 	int				content;
// 	int				max;
// 	int				min;
// 	int				mid;
// 	int				flag;
// }					t_stack;

// typedef struct l_list
// {
// 	int		t_size;
// 	t_stack	*a;
// 	t_stack	*b;
// 	t_stack *tmp;
// }	t_list;

typedef struct a_list
{
	int				nb;
	int				position;
	int				range;
	int				sort;
	struct a_list	*next;
	struct a_list	*prev;
}	t_stack;

typedef struct l_list
{
	int		pivot;
	int		max_range;
	int		t_size;
	int		size_a;
	int		size_b;
	int		n_1;
	int		n_2;
	int		n_3;
	int		show_output;
	t_stack	*a;
	t_stack	*b;
	t_stack	*top_a;
	t_stack	*bottom_a;
	t_stack	*top_b;
	t_stack	*bottom_b;
	t_stack	*tmp;
	t_stack	*range_stack;
}	t_list;

// t_stack	*stack_add(t_stack *stack, t_stack *new);
// t_stack	*stack_init(t_stack *a, t_stack *new);
// t_stack	*stack_last(t_stack *lst);
// t_stack *stack_new(int *new);
// t_stack	get_numbers(char *av, t_stack *stack_a);

char	**ft_split(char const *s, char c);

#endif