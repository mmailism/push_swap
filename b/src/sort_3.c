/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/09 20:14:18 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	tiny_sort_3(t_stack **stack_a)
{
	if ((*stack_a))
	{
		if ((*stack_a)->nbr > (*stack_a)->next->next->nbr
			&& (*stack_a)->nbr > (*stack_a)->next->nbr)
			ra(stack_a, 0);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a, 0);
		if ((*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
		{
			rra(stack_a, 0);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a, 0);
			else
				return ;
		}
		else
			return ;
	}
}

void	tiny_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	if (!(is_sort(*stack_a)))
	{
		pb(stack_a, stack_b, 0);
		tiny_sort_3(stack_a);
		if ((*stack_b)->nbr < (*stack_a)->nbr)
			pa(stack_a, stack_b, 0);
		if ((*stack_b) && (*stack_b)->nbr > (*stack_a)->next->next->nbr)
		{
			pa(stack_a, stack_b, 0);
			ra(stack_a, 0);
		}
		while (*stack_b)
		{
			ra(stack_a, 0);
			if ((*stack_b)->nbr < (*stack_a)->nbr)
				pa(stack_a, stack_b, 0);
		}
		while (!is_sort(*stack_a))
			ra(stack_a, 0);
	}
}
