/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/01 13:25:50 by iammai           ###   ########.fr       */
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

static void	sort4_pos2(t_list *stack)
{
	if (stack->a->nb)
	{
		sa(stack);
		pb(stack);
		tiny_sort_3(stack);
		pa(stack);
		ra(stack);
	}
	else
		return ;
}

static void	sort4_pos3(t_list *stack)
{
	if (stack->a->nb)
	{
		rra(stack);
		rra(stack);
		pb(stack);
		tiny_sort_3(stack);
		pa(stack);
		ra(stack);
	}
	else
		return ;
}

static void	sort4_pos4(t_list *stack)
{
	if (stack->a->nb)
	{
		rra(stack);
		pb(stack);
		tiny_sort_3(stack);
		pa(stack);
		ra(stack);
	}
	else
		return ;
}

void	tiny_sort_4(t_list *stack)
{
	if (stack->a->nb > stack->a->next->nb
		&& stack->a->nb > stack->a->next->next->nb
		&& stack->a->nb > stack->a->next->next->nb
		&& stack->a->nb > stack->a->next->next->next->nb)
	{
		pb(stack);
		tiny_sort_3(stack);
		pa(stack);
		ra(stack);
	}
	else if (stack->a->next->nb > stack->a->nb
		&& stack->a->next->nb > stack->a->next->next->nb
		&& stack->a->next->nb > stack->a->next->next->nb)
		sort4_pos2(stack);
	else if (stack->a->next->next->nb > stack->a->nb
		&& stack->a->next->next->nb > stack->a->next->nb
		&& stack->a->next->next->nb > stack->a->next->next->next->nb)
		sort4_pos3(stack);
	else if (stack->a->next->next->next->nb > stack->a->nb
		&& stack->a->next->next->next->nb > stack->a->next->nb
		&& stack->a->next->next->next->nb > stack->a->next->next->nb)
		sort4_pos4(stack);
	else
		return ;
}
