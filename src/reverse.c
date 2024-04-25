/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	rra(t_list *stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	current = stack->a;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = stack->a;
	prev->next = NULL;
	stack->bottom_a = prev;
	stack->a = current;
	stack->top_a = stack->a;
	printf("rra\n");
}