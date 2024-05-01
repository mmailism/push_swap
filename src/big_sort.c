/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:27 by iammai            #+#    #+#             */
/*   Updated: 2024/05/01 13:51:22 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	find_max(t_list *stack)
{
	int		max;
	t_stack	*curr;

	if (stack == NULL || stack->a == NULL)
	{
		printf("The list is empty.\n");
		error_free(stack);
	}
	max = stack->a->nb;
	curr = stack->a->next;
	while (curr != NULL)
	{
		// Update max if the current node's value is greater
		if (curr->nb > max)
			max = curr->nb;
        // Move to the next node
		curr = curr->next;
    }
	stack->max = max;
	return (stack->max);
}

int	find_min(t_list *stack)
{
	int		min;
	t_stack	*curr;

	if (stack == NULL || stack->a == NULL)
	{
		printf("The list is empty.\n");
		error_free(stack);
	}
	min = stack->a->nb;
	curr = stack->a->next;
	while (curr != NULL)
	{
		// Update max if the current node's value is greater
		if (curr->nb < min)
			min = curr->nb;
		// Move to the next node
		curr = curr->next;
	}
	stack->min = min;
	return (min);
}

int	find_mid(t_list *stack)
{
	int	max;
	int	min;
	int	mid;

	max = find_max(stack);
	min = find_min(stack);
	mid = (max + min) / 2;
	stack->mid = mid;
    // printf("The middle value between %d and %d is: %d\n", min, max, mid);
	// printf("%d\n", mid);
    return (mid);
}

void	push(t_list *stack)
{
	int		max;
	int		min;
	int		mid;
	t_stack *curr;

	max = find_max(stack);
	min = find_min(stack);
	mid = find_mid(stack);
	curr = stack->a->next;
    printf("The middle value between %d and %d is: %d\n", min, max, mid);
	while (curr != NULL)
	{
		if (stack->a->nb < max)
		{
			ra(stack);
		}
		curr = curr->next;
	}
	return ;
}

void	big_sort(t_list *stack)
{
	// int	max;
	// int	min;
	// int	mid;
	if (stack_len(stack) < 100)
	{
		print_stack(stack->a, 1);
		push(stack);
		print_stack(stack->a, 1);
		print_stack(stack->b, 2);
	}
	if (stack_len(stack) < 500 && stack_len(stack) > 100)
		printf("sort500\n");
}