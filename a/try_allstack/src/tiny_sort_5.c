/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/05 18:43:11 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

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

static void	push_b_pos_2(t_stack **a, t_stack **b)
{
	if ((*b) && (*b)->next == NULL)
	{
		if ((*b)->nbr < (*a)->nbr)
		{
			pa(a, b, 0);
			return ;
		}
		if ((*b)->nbr > (*a)->nbr && (*b)->nbr > (*a)->next->nbr
			&& (*b)->nbr > (*a)->next->next->nbr
			&& (*b)->nbr > (*a)->next->next->next->nbr)
		{
			pa(a, b, 0);
			ra(a, 0);
			return ;
		}
		if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr)
		{
			pa(a, b, 0);
			sa(a, 0);
		}
	}
}

static void	b1_less_all_a(t_stack **a, t_stack **b)
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

static void	b1_less_a2(t_stack **a, t_stack **b)
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
		&& (*b)->next->nbr < (*a)->next->next->nbr 
		&& (*b)->next != NULL)
	{
		rrr(a, b, 0);
		pa(a, b, 0);
		ra(a, 0);
		ra(a, 0);
		return ;
	}
	if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr
		&& (*b)->next->nbr > (*a)->next->nbr
		&& (*b)->next->nbr > (*a)->next->next->nbr
		&& (*b)->next != NULL)
	{
		pa(a, b, 0);
		sa(a, 0);
	}
}

static void	b1_less_a3(t_stack **a, t_stack **b)
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

static void	b1_more_a3(t_stack **a, t_stack **b)
{
	if ((*b)->nbr > (*a)->next->next->nbr && (*b)->next->nbr > (*a)->next->next->nbr
		&& (*b)->next != NULL)
	{
		pa(a, b, 0);
		ra(a, 0);
		return ;
	}
}

static void	push_b_pos_1(t_stack **a, t_stack **b)
{
	if ((*a) && (*b) && (*b)->next != NULL)
	{
		if ((*b)->nbr < (*a)->nbr && (*b)->next != NULL)
		{
			if ((*b)->nbr < (*a)->nbr && (*b)->next->nbr < (*a)->nbr && (*b)->next != NULL)
			{
				sb(b, 0);
				pa(a, b, 0);
				return ;
			}
			b1_less_all_a(a, b);
		}
		if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr && (*b)->next != NULL)
			b1_less_a2(a, b);
		if ((*b)->nbr > (*a)->next->nbr && (*b)->nbr < (*a)->next->next->nbr 
			&& (*b)->next != NULL)
		{
			b1_less_a3(a, b);
		}
		if ((*b)->nbr > (*a)->next->next->nbr && (*b)->next != NULL)
			b1_more_a3(a, b);
		else
			return ;	
	}
}

void	tiny_sort_5(t_stack **a, t_stack **b)
{
	if (*a != NULL)
	{
		if ((*a)->nbr > (*a)->next->next->next->next->nbr && (*a)->nbr > (*a)->next->next->next->nbr
			&& (*a)->nbr > (*a)->next->next->nbr && (*a)->nbr > (*a)->next->nbr)
		{
			if ((*a)->next->nbr < (*a)->next->next->nbr
			&& (*a)->next->next->nbr < (*a)->next->next->next->nbr && (*a)->next->next->next->nbr < (*a)->next->next->next->next->nbr )
			{
				ra(a, 0);
				return ;
			}
		}
		pb(a, b, 0);
		pb(a, b, 0);
		tiny_sort_3(a);
	}
	if ((*b))
		if ((*b)->nbr > (*b)->next->nbr)
			sb(b, 0);
	if ((*b) && (*b)->next != NULL)
		push_b_pos_1(a, b);
	if ((*b) && (*b)->next == NULL)
		push_b_pos_2(a, b);
}
