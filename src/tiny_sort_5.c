/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_5.c                 	                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	push_b_pos_2(t_list *stack)
{
	if (stack->b && stack->b->next == NULL)
	{
		if (stack->b->nb < stack->a->nb)
		{
			pa(stack);
			return ;
		}
		if (stack->b->nb > stack->a->nb && stack->b->nb > stack->a->next->nb
			&& stack->b->nb > stack->a->next->next->nb
			&& stack->b->nb > stack->a->next->next->next->nb)
		{
			pa(stack);
			ra(stack);
			return ;
		}
		if (stack->b->nb > stack->a->nb && stack->b->nb < stack->a->next->nb)
		{
			pa(stack);
			sa(stack);
		}
	}
}

static void	b1_less_all_a(t_list *stack)
{
	if (stack->b->nb < stack->a->nb && stack->b->next->nb > stack->a->nb
		&& stack->b->next->nb < stack->a->next->nb && stack->b->next != NULL)
	{
		sb(stack);
		pa(stack);
		sa(stack);
		return ;
	}
	if (stack->b->nb < stack->a->nb && stack->b->next->nb > stack->a->next->nb
		&& stack->b->next->nb < stack->a->next->next->nb
		&& stack->b->next != NULL)
	{
		sb(stack);
		rra(stack);
		pa(stack);
		ra(stack);
		ra(stack);
		return ;
	}
	if (stack->b->nb < stack->a->nb && stack->b->next->nb > stack->a->next->nb
		&& stack->b->next->nb > stack->a->next->next->nb
		&& stack->b->next != NULL)
		pa(stack);
}

static void	b1_less_a2(t_list *stack)
{
	if (stack->b->nb > stack->a->nb && stack->b->nb < stack->a->next->nb
		&& stack->b->next->nb < stack->a->next->nb && stack->b->next != NULL)
	{
		sb(stack);
		pa(stack);
		sa(stack);
		return ;
	}
	if (stack->b->nb > stack->a->nb && stack->b->nb < stack->a->next->nb
		&& stack->b->next->nb > stack->a->next->nb
		&& stack->b->next->nb < stack->a->next->next->nb 
		&& stack->b->next != NULL)
	{
		rrr(stack);
		pa(stack);
		ra(stack);
		ra(stack);
		return ;
	}
	if (stack->b->nb > stack->a->nb && stack->b->nb < stack->a->next->nb
		&& stack->b->next->nb > stack->a->next->nb
		&& stack->b->next->nb > stack->a->next->next->nb
		&& stack->b->next != NULL)
	{
		pa(stack);
		sa(stack);
	}
}

static void	b1_less_a3(t_list *stack)
{
	if (stack->b->nb > stack->a->next->nb && stack->b->nb < stack->a->next->next->nb
		&& stack->b->next->nb < stack->a->next->next->nb && stack->b->next != NULL)
	{
		rrr(stack);
		pa(stack);
		pa(stack);
		ra(stack);
		pa(stack);
		ra(stack);
		pb(stack);
		return ;
	}
	if (stack->b->nb > stack->a->next->nb && stack->b->nb < stack->a->next->next->nb
		&& stack->b->next->nb > stack->a->next->next->nb && stack->b->next != NULL)
	{
		rra(stack);
		pa(stack);
		ra(stack);
		ra(stack);
		return ;
	}
	else
		return ;
}

static void	b1_more_a3(t_list *stack)
{
	if (stack->b->nb > stack->a->next->next->nb && stack->b->next->nb > stack->a->next->next->nb
		&& stack->b->next != NULL)
	{
		pa(stack);
		ra(stack);
		return ;
	}
}

static void	push_b_pos_1(t_list *stack)
{
	if (stack->a && stack->b && stack->b->next != NULL)
	{
		if (stack->b->nb < stack->a->nb && stack->b->next != NULL)
		{
			if (stack->b->nb < stack->a->nb && stack->b->next->nb < stack->a->nb && stack->b->next != NULL)
			{
				sb(stack);
				pa(stack);
				return ;
			}
			b1_less_all_a(stack);
		}
		if (stack->b->nb > stack->a->nb && stack->b->nb < stack->a->next->nb && stack->b->next != NULL)
			b1_less_a2(stack);
		if (stack->b->nb > stack->a->next->nb && stack->b->nb < stack->a->next->next->nb 
			&& stack->b->next != NULL)
		{
			b1_less_a3(stack);
		}
		if (stack->b->nb > stack->a->next->next->nb && stack->b->next != NULL)
			b1_more_a3(stack);
		else
			return ;	
	}
}

void	tiny_sort_5(t_list *stack)
{
	if (stack->a)
	{
		if (stack->a->nb > stack->a->next->next->next->next->nb && stack->a->nb > stack->a->next->next->next->nb
			&& stack->a->nb > stack->a->next->next->nb && stack->a->nb > stack->a->next->nb)
		{
			if (stack->a->next->nb < stack->a->next->next->nb
			&& stack->a->next->next->nb < stack->a->next->next->next->nb && stack->a->next->next->next->nb < stack->a->next->next->next->next->nb )
			{
				ra(stack);
				return ;
			}
		}
		pb(stack);
		pb(stack);
		tiny_sort_3(stack);
	}
	if (stack->b)
		if (stack->b->nb > stack->b->next->nb)
			sb(stack);
	if (stack->b && stack->b->next != NULL)
		push_b_pos_1(stack);
	if (stack->b && stack->b->next == NULL)
		push_b_pos_2(stack);
}