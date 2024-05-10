/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:38:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/10 13:38:10 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	find_max(t_stack *head)
{
	t_stack	*current;
	int		max;

	if (head == NULL)
		exit(EXIT_FAILURE);
	max = head->nbr;
	current = head->next;
	while (current != NULL)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *head)
{
	int		min;
	t_stack	*current;

	min = head->nbr;
	current = head->next;
	while (current != NULL)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

int	find_mid(int min, int max)
{
	int	mid;

	mid = (min + max) / 2;
	return (mid);
}

int	find_max_i(t_stack *copy, int max)
{
	int	i;

	i = 0;
	while (copy->nbr != max)
	{
		copy = copy->next;
		++i;
	}
	return (i);
}
