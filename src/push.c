/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailism <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2023/09/22 17:23:10 by mailism          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	pa(t_list *stack)
{
	t_stack	*tmp;

	if (stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		tmp->next = stack->a;
		stack->a = tmp;
		printf("pa\n");
	}
	else
		return ;
}

void	pb(t_list *stack)
{
	t_stack	*tmp;

	if (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		tmp->next = stack->b;
		stack->b = tmp;
		printf("pb\n");
	}
	else
		return ;
}
