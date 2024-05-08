/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/09 00:34:47 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		length;
	int		i;
	int		j;
	int		max;
	t_stack	*copy;

	copy = *stack_b;
	length = stack_size(*stack_b);
	j = 0;
	i = 0;
	max = find_max(copy);
	i = find_max_i(copy, max);
	if (i < length / 2)
	{
		while (j++ < i)
			rb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	else
	{
		while (i++ < length - 1)
			rrb(stack_b, 0);
		rrb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	mid;

	i = 0;
	mid = stack_size(*stack_a) / 5;
	if (stack_size(*stack_a) > 100)
		mid = stack_size(*stack_a) / 10;
	while (*stack_a)
	{
		if ((*stack_a)->nbr <= i)
		{
			pb(stack_a, stack_b, 0);
			i += 1;
		}
		else if ((*stack_a)->nbr <= (i + mid))
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i += 1;
		}
		else
			ra(stack_a, 0);
	}
}

void	pushswap(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!is_sort(*stack_a))
	{
		ft_push_b(stack_a, &stack_b);
		while (stack_b)
			sort_b_to_a(stack_a, &stack_b);
	}
	free(stack_b);
}
