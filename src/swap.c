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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sb(t_list *stack)
{
	int	tmp;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b->next->nb;
		stack->b->next->nb = stack->b->nb;
		stack->b->nb = tmp;
		printf("sb\n");
		// if (show_output("sb\n", stack->show_output) == -1)
		// 	return ;
			// error_free(stack);
		stack->top_b = stack->b;
	}
	else
		return ;
}

void	sa(t_list *stack)
{
	int	tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a->next->nb;
		stack->a->next->nb = stack->a->nb;
		stack->a->nb = tmp;
		printf("sa\n");
			// error_free(stack);
		// stack->top_a = stack->a;
		// if (stack->size_a == 2)
		// 	stack->bottom_a = stack->a->next;
	}
	else
		return ;
}

void	ss(t_list *stack)
{
	int	tmp;

	if (stack)
	{
		if (stack->a && stack->a->next)
		{
			tmp = stack->a->next->nb;
				print_stack(stack->a, 1);
			stack->a->next->nb = stack->a->nb;
				print_stack(stack->a, 1);
			stack->a->nb = tmp;
				print_stack(stack->a, 1);
		}
		if (stack->b && stack->b->next)
		{
			tmp = stack->b->next->nb;
				print_stack(stack->b, 1);
			stack->a->next->nb = stack->a->nb;
				print_stack(stack->b, 1);
			stack->b->nb = tmp;
				print_stack(stack->b, 1);
		}
		print_stack(stack->a, 1);
		print_stack(stack->b, 2);
		printf("ss\n");
	}
	else
		return ;
}
