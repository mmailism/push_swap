/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:24:59 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/10 14:25:02 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	tiny_sort_5(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->nbr == find_max(*a))
			pb(a, b, 0);
		else
			rra(a, 0);
	}
	tiny_sort_3(a);
	while (!(stack_size(*b) == 0))
	{
		if ((*b)->nbr)
		{
			pa(a, b, 0);
			ra(a, 0);
		}
	}
}
