/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/09 00:02:15 by iammai           ###   ########.fr       */
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

static void	sort4_pos2(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nbr)
	{
		sa(stack_a, 0);
		pb(stack_a, stack_b, 0);
		tiny_sort_3(stack_a);
		pa(stack_a, stack_b, 0);
		ra(stack_a, 0);
	}
	else
		return ;
}

static void	sort4_pos3(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nbr)
	{
		rra(stack_a, 0);
		rra(stack_a, 0);
		pb(stack_a, stack_b, 0);
		tiny_sort_3(stack_a);
		pa(stack_a, stack_b, 0);
		ra(stack_a, 0);
	}
	else
		return ;
}

static void	sort4_pos4(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nbr)
	{
		rra(stack_a, 0);
		pb(stack_a, stack_b, 0);
		tiny_sort_3(stack_a);
		pa(stack_a, stack_b, 0);
		ra(stack_a, 0);
	}
	else
		return ;
}

void	tiny_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->nbr > (*stack_a)->next->next->nbr
		&& (*stack_a)->nbr > (*stack_a)->next->next->nbr
		&& (*stack_a)->nbr > (*stack_a)->next->next->next->nbr)
	{
		pb(stack_a, stack_b, 0);
		tiny_sort_3(stack_a);
		pa(stack_a, stack_b, 0);
		ra(stack_a, 0);
	}
	else if ((*stack_a)->next->nbr > (*stack_a)->nbr
		&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr
		&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
		sort4_pos2(stack_a, stack_b);
	else if ((*stack_a)->next->next->nbr > (*stack_a)->nbr
		&& (*stack_a)->next->next->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->next->nbr > (*stack_a)->next->next->next->nbr)
		sort4_pos3(stack_a, stack_b);
	else if ((*stack_a)->next->next->next->nbr > (*stack_a)->nbr
		&& (*stack_a)->next->next->next->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->next->next->nbr > (*stack_a)->next->next->nbr)
		sort4_pos4(stack_a, stack_b);
	else
		return ;
}
