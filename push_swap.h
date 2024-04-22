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
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	int				content;
	int				max;
	int				min;
	int				mid;
	int				flag;
}					t_stack;

typedef struct l_list
{
	int		t_size;
	t_stack	*a;
	t_stack	*b;
	t_stack *tmp;
}	t_list;


// t_stack	*stack_add(t_stack *stack, t_stack *new);
// t_stack	*stack_init(t_stack *a, t_stack *new);
// t_stack	*stack_last(t_stack *lst);
// t_stack *stack_new(int *new);
// t_stack	get_numbers(char *av, t_stack *stack_a);

char	**ft_split(char const *s, char c);

#endif