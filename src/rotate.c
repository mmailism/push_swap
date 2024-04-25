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

void	ra(t_list *stack)
{
	t_stack	*head;
	t_stack	*curr;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	head = stack->a->next;
	curr = stack->a;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = stack->a;
	stack->a->next = NULL;
	stack->a = head;
	printf("ra\n");

	// if (show_output("ra\n", stack->show_output) == -1)
	// 		return ;
		// error_free(stack);
}

void	rb(t_list *stack)
{
	t_stack	*head;
	t_stack	*curr;

	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	head = stack->b->next;
	curr = stack->b;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = stack->b;
	stack->b->next = NULL;
	stack->b = head;
	printf("rb\n");

	// if (show_output("ra\n", stack->show_output) == -1)
	// 		return ;
		// error_free(stack);
}