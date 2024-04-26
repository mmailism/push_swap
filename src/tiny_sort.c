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
//! find funtion find highest now
void	sort_a_b(t_list *stack)
{
	if (stack->b && stack->a)
	{
		if (stack->b->nb > stack->a->nb && stack->b->nb > stack->a->next->nb
			&& stack->b->nb > stack->a->next->next->nb)
		{
			pb(stack);
			ra(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		}
		if (stack->b->nb > stack->a->nb && stack->b->nb > stack->a->next->nb
			&& stack->b->nb < stack->a->next->next->nb)
		{
			pb(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
			ra(stack);
						print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		}
		if (stack->b->nb > stack->a->nb && stack->b->nb > stack->a->next->nb
			&& stack->b->nb < stack->a->next->next->nb)
		{
			pb(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		}
		if (stack->b->nb < stack->a->nb)
		{
			pb(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		}
	}
}

void	check_pos(t_list *stack)
{
	if (stack->a->nb > stack->a->next->nb
		&& stack->a->nb > stack->a->next->next->nb
		&& stack->a->nb > stack->a->next->next->next->nb
		&& stack->a->nb > stack->a->next->next->next->next->nb)
	{
		pa(stack);
	}
	else
		return ;
}

void	tiny_sort_5(t_list *stack)
{

	if (stack->a)
	{
		if (stack->a)
		{
			// check_pos(stack);
			pa(stack);
			pa(stack);
			tiny_sort_3(stack);
				print_stack(stack->a, 1);
				print_stack(stack->b, 2);
			
		}
	}
	if (stack->b)
	{
		if (stack->b->nb < stack->b->next->nb)
		{
			sb(stack);
			print_stack(stack->a, 1);
				print_stack(stack->b, 2);
		}
	}
	sort_a_b(stack);
}
