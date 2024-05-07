/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                   	                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ra(t_stack **stack_a, int j)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = ft_lstlast(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = ft_lstlast(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	tmp = *stack_a;
	*stack_a = ft_lstlast(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp = *stack_b;
	*stack_b = ft_lstlast(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}
