/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/01 15:23:26 by iammai           ###   ########.fr       */
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
}
