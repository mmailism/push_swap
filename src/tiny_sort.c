/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	tiny_sort_3(t_list *stack)
{
	if (stack->a)
	{
		if (stack->a->nb > stack->a->next->next->nb
			&& stack->a->nb > stack->a->next->nb)
		{
			ra(stack);
		}
		if (stack->a->nb > stack->a->next->nb)
			sa(stack);
		if (stack->a->next->nb > stack->a->next->next->nb)
		{
			rra(stack);
			if (stack->a->nb > stack->a->next->nb)
				sa(stack);
			else
				return ;
		}
		else
			return ;
	}
}

void	tiny_sort_5(t_list *stack)
{
	if (stack->a)
	{
		if (stack->a->nb && stack->a->next->nb)
		{
			pa(stack);
				print_stack(stack->a, 1);
				print_stack(stack->b, 2);
			pa(stack);
				print_stack(stack->a, 1);
				print_stack(stack->b, 2);
		}
		tiny_sort_3(stack);
	}
	if (stack->b)
	{
		if (stack->b->nb > stack->b->next->nb)
		{
			sb(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		}
	}
}