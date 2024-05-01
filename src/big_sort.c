/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:27 by iammai            #+#    #+#             */
/*   Updated: 2024/05/01 18:47:05 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

// static int	find_min(t_list *stack)
// {
// 	int		min;
// 	t_stack	*curr;

// 	if (stack == NULL || stack->a == NULL)
// 	{
// 		printf("The list is empty.\n");
// 		error_free(stack);
// 	}
// 	min = stack->a->nb;
// 	curr = stack->a->next;
// 	while (curr != NULL)
// 	{
// 		// Update max if the current node's value is greater
// 		if (curr->nb < min)
// 			min = curr->nb;
// 		// Move to the next node
// 		curr = curr->next;
// 	}
// 	stack->min = min;
// 	return (min);
// }

// int	find_mid(t_list *stack)
// {
// 	int	max;
// 	int	min;
// 	int	mid;

// 	max = find_max(stack);
// 	min = find_min(stack);
// 	mid = (max + min) / 2;
// 	stack->mid = mid;
//     // printf("The middle value between %d and %d is: %d\n", min, max, mid);
// 	// printf("%d\n", mid);
//     return (mid);
// }

// void	push(t_list *stack)
// {
// 	// int		max;
// 	// int		min;
// 	// int		mid;
// 	t_stack *curr;

// 	// max = find_max(stack);
// 	// min = find_min(stack);
// 	curr = stack->a;
//     // printf("The middle value between %d and %d is: %d\n", min, max, mid);
// 	while (curr != NULL)
// 	{
// 		if (curr->nb > find_mid(stack))
// 		{
// 			more_mid(stack);
// 		}
// 		else if (curr->nb < find_mid(stack))
// 		{
// 			printf("< mid\n");
// 		}
// 		else
// 			printf("= mid\n");
// 		// curr = stack->tmp;
// 		curr = curr->next;
// 		// 	print_stack(stack->a, 1);
// 		// print_stack(stack->b, 2);
// 	}
// 	return ;
// }

static int	find_max(t_list *stack)
{
	int		max;
	t_stack	*curr;

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
	// stack->max = max;
	return (max);
}

int	find_max_i(t_list *copy, int max)
{
	int	i;
	t_stack	*copy_b;

	i = 0;
	copy_b = copy->b; 
	while (copy_b != NULL && copy_b->nb != max)
	{
		i++;
		copy_b = copy_b->next;
	}
	return (i);
}

void	prepare_b(t_list *stack)
{
	int		length;
	int		i;
	int		j;
	int		max;
	t_list	*copy;

	copy = stack;
	length = stack_len(stack);
	j = 0;
	max = find_max(copy);
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

void	big_sort(t_list *stack)
{
	int	i;
	int	len_stack;

	i = 0;
	len_stack = 15;
	if (stack_len(stack) > 100)
		len_stack = 30;
	while (!is_sort(stack))
	{
		print_stack(stack->a, 1);
		print_stack(stack->b, 2);
		if (stack->a->nb <= i)
		{
			pb(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
			i++;
		}
		else if (stack->a->nb <= (i + len_stack))
		{
			pb(stack);
			rb(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
			i++;
		}
		else
		{
			ra(stack);
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
			i++;
		}
	}
	while (stack->b)
		prepare_b(stack);
}

// void	create_rank(t_list *stack)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_tmp;
// 	int		pivot;
// 	int		start;

// 	create_stack_tmp(stack);
// 	pivot = find_pivot(stack->tmp, stack->tmp->nb);
// 	start = find_start(stack->tmp, pivot);
// 	easy_sort(stack, start, pivot);
// 	stack_a = stack->a;
// 	stack_tmp = stack->tmp;
// 	while (stack_a)
// 	{
// 		find_rank(stack_a, stack_tmp);
// 		stack_a = stack_a->next;
// 	}
// }

// void	big_sort(t_list *stack)
// {
// 	int		position;
// 	int		max_range;

// 	create_rank(stack);
// 	first_partition(stack);
// 	max_range = stack->max_range - 1;
// 	while (max_range > 0)
// 	{
// 		position = find_position(stack, max_range);
// 		max_range = range_sort(stack, max_range, position);
// 	}
// }
