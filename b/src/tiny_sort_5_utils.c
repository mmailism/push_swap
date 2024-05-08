/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_5_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/09 00:07:53 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	b1_less_all_a(t_stack **a, t_stack **b)
{
	if ((*b)->nbr < (*a)->nbr && (*b)->next->nbr > (*a)->nbr
		&& (*b)->next->nbr < (*a)->next->nbr && (*b)->next != NULL)
	{
		sb(b, 0);
		pa(a, b, 0);
		sa(a, 0);
		return ;
	}
	if ((*b)->nbr < (*a)->nbr && (*b)->next->nbr > (*a)->next->nbr
		&& (*b)->next->nbr < (*a)->next->next->nbr
		&& (*b)->next != NULL)
	{
		sb(b, 0);
		rra(a, 0);
		pa(a, b, 0);
		ra(a, 0);
		ra(a, 0);
		return ;
	}
	if ((*b)->nbr < (*a)->nbr && (*b)->next->nbr > (*a)->next->nbr
		&& (*b)->next->nbr > (*a)->next->next->nbr
		&& (*b)->next != NULL)
		pa(a, b, 0);
}

void	b1_less_a2(t_stack **a, t_stack **b)
{
	if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr
		&& (*b)->next->nbr < (*a)->next->nbr && (*b)->next != NULL)
	{
		sb(b, 0);
		pa(a, b, 0);
		sa(a, 0);
		return ;
	}
	if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr
		&& (*b)->next->nbr > (*a)->next->nbr
		&& (*b)->next->nbr < (*a)->next->next->nbr && (*b)->next != NULL)
	{
		rrr(a, b, 0);
		pa(a, b, 0);
		ra(a, 0);
		ra(a, 0);
		return ;
	}
	if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr
		&& (*b)->next->nbr > (*a)->next->nbr
		&& (*b)->next->nbr > (*a)->next->next->nbr && (*b)->next != NULL)
	{
		pa(a, b, 0);
		sa(a, 0);
	}
}

void	b1_less_a3(t_stack **a, t_stack **b)
{
	if ((*b)->nbr > (*a)->next->nbr && (*b)->nbr < (*a)->next->next->nbr
		&& (*b)->next->nbr < (*a)->next->next->nbr && (*b)->next != NULL)
	{
		rrr(a, b, 0);
		pa(a, b, 0);
		pa(a, b, 0);
		ra(a, 0);
		pa(a, b, 0);
		ra(a, 0);
		pb(a, b, 0);
		return ;
	}
	if ((*b)->nbr > (*a)->next->nbr && (*b)->nbr < (*a)->next->next->nbr
		&& (*b)->next->nbr > (*a)->next->next->nbr && (*b)->next != NULL)
	{
		rra(a, 0);
		pa(a, b, 0);
		ra(a, 0);
		ra(a, 0);
		return ;
	}
	else
		return ;
}

void	b1_more_a3(t_stack **a, t_stack **b)
{
	if ((*b)->nbr > (*a)->next->next->nbr
		&& (*b)->next->nbr > (*a)->next->next->nbr
		&& (*b)->next != NULL)
	{
		pa(a, b, 0);
		ra(a, 0);
		return ;
	}
}
