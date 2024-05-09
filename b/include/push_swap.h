/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:38:32 by iammai            #+#    #+#             */
/*   Updated: 2024/05/09 17:05:41 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//stack.c
void	stack_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*stack_new(int content);
t_stack	*ft_lstlast(t_stack *lst);
int		stack_size(t_stack *lst);
int		is_sort(t_stack *stack_a);

//stack_util.c
int		atoi_pushswap(char *str, t_stack *stack);
int		error_syntax(char *str_nbr);
char	**split_to_stack(t_stack *stack, char *str);

//tiny_sort.c
void	tiny_sort_3(t_stack **stack_a);
void	tiny_sort_4(t_stack **stack_a, t_stack **stack_b);

//tiny_sort_5.c
void	tiny_sort_5(t_stack **stack_a, t_stack **stack_b);

//tiny_sort_5_utils.c
void	b1_less_all_a(t_stack **a, t_stack **b);
void	b1_less_a2(t_stack **a, t_stack **b);
void	b1_less_a3(t_stack **a, t_stack **b);
void	b1_more_a3(t_stack **a, t_stack **b);

//big_sort.c
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
void	pushswap(t_stack **stack_a);

//big_sort_utils.c
int		find_min(t_stack *head);
int		find_max(t_stack *head);
int		find_mid(int min, int max);
int		find_max_i(t_stack *copy, int max);

//free.c
void	error_free(t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(t_stack **stack, int mode);
void	ft_freestr(char **lst);
char	**free_split(char **data);

//utils_in_utils.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t n);
size_t	ft_strlen(const char *str);

#endif