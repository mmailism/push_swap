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
	t_stack *tmp;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	if (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		tmp->next = stack->b;
        stack->b = tmp;
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		// if (show_output("pa\n", stack->show_output) == -1)
		// 	return ;
		printf("pa\n");
            // error_free(stack);
	}
	else
		return ;
}