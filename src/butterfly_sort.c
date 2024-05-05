/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:47:24 by iammai            #+#    #+#             */
/*   Updated: 2024/05/03 15:02:15 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	find_max_i(t_stack *copy, int max)
{
	int	i;

	i = 0;
	while (copy->nb != max)
	{
		i++;
		copy = copy->next;
	}
	return (i);
}

int	find_max(t_stack *copy, int *p_length)
{
	int	max;

	max = -1;
	while (copy)
	{
		if (copy->nb > max)
			max = copy->nb;
		copy = copy->next;
		(*p_length)++;
	}
	return (max);
}

void	prepare_b(t_list *stack)
{
	int		length;
	int		i;
	int		j;
	int		max;
	t_stack	*copy;

	copy = stack->b;
	length = 0;
	j = 0;
	i = 0;
	max = find_max(copy, &length);
	i = find_max_i(copy, max);
	if (i < length / 2)
	{
		while (j++ < i)
			rb(stack);
		pa(stack);
	}
	else
	{
		while (i++ < length - 1)
			rrb(stack);
		rrb(stack);
		pa(stack);
	}
}

void	sort_many(t_list *stack, int argc)
{
	int	i;
	int	mystery_number;
    t_stack *a;
    t_stack *b;

    a = stack->a;
    b = stack->b;
	i = 0;
	mystery_number = 15;
	if (argc > 100)
		mystery_number = 30;
	while (a)
	{
		if (a->nb <= i)
		{
			pb(stack);
			i++;
		}
		else if (a->nb <= (i + mystery_number))
		{
			pb(stack);
			rb(stack);
			i++;
		}
		else
			ra(stack);
	}
	while (b)
		prepare_b(stack);
}