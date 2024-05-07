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
# include <stdio.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				max;
	int				min;
	// struct s_stack	last;
}	t_stack;

void	pushswap_try(t_stack **stack_a);

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
int		stack_size(t_stack *lst);

//stack_util.c
int		atoi_pushswap(const char *str);

//tiny_sort.c
void	tiny_sort_3(t_stack **stack_a);
void	tiny_sort_4(t_stack **stack_a, t_stack **stack_b);

//tiny_sort_5.c
void	tiny_sort_5(t_stack **stack_a, t_stack **stack_b);

//big_sort.c
// void	push_swap(t_stack **stack_a);
// int	ft_find_place_a(t_stack *stack_a, int nbr_push);
int	ft_find_place_b(t_stack *stack_b, int nbr_push);

//big_sort_utils.c
// void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);
int		ft_find_index(t_stack *a, int nbr);

//case_a.c
// int	ft_rotate_type_ab(t_stack *a, t_stack *b);
// int	ft_case_rarb_a(t_stack *a, t_stack *b, int c);
// int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
// int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
// int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c);

//case_b.c
// int	ft_rotate_type_ba(t_stack *a, t_stack *b);
// int	ft_case_rarb(t_stack *a, t_stack *b, int c);
// int	ft_case_rrarrb(t_stack *a, t_stack *b, int c);
// int	ft_case_rrarb(t_stack *a, t_stack *b, int c);
// int	ft_case_rarrb(t_stack *a, t_stack *b, int c);

//apply.c
// int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
// int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
// int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
// int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);

//free.c
void	error_free(t_stack *stack);
void	free_stack(t_stack *stack);

#endif