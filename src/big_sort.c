/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:27 by iammai            #+#    #+#             */
/*   Updated: 2024/05/03 17:43:51 by iammai           ###   ########.fr       */
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

int	stack_len_bigsort(t_stack *stack)
{
	int		count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

void	set_current_pos(t_stack *stack)
{
	int	i;
	int	center_line;
	
	i = 0;
	center_line = stack_len_bigsort(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	finish_rotation(t_stack *stack_name, t_stack *smallest_number,
						char name, t_list *stack)
{
	while (stack_name != smallest_number)
	{
		if (name == 'a')
		{
			if (smallest_number->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (smallest_number->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

// t_stack	*return_cheapest(t_stack *stack)
// {
// 	if (stack == NULL)
// 		return (NULL);
// 	while (stack)
// 	{
// 		if (stack->cheapest)
// 			return (stack);
// 		stack = stack->next;
// 	}
// 	return (NULL);
// }

// static void	rotate_both(t_stack *a, t_stack *b, t_stack *cheapest_number, t_list *stack)
// {
// 	while (a != cheapest_number->target_number
// 		&& b != cheapest_number)
// 		rr(stack);
// 	set_current_pos(a);
// 	set_current_pos(b);
// }

// static void	reverse_rotate_both(t_stack *a, t_stack *b,
// 								t_stack *cheapest_number,
// 								t_list *stack)
// {
// 	while (a != cheapest_number->target_number
// 		&& b != cheapest_number)
// 		rrr(stack);
// 	set_current_pos(a);
// 	set_current_pos(b);
// }

// static void	move_price(t_stack *a, t_stack *b, t_list *stack)
// {
// 	t_stack	*cheapest_number;

// 	cheapest_number = return_cheapest(b);
// 	if (cheapest_number->above_median
// 		&& cheapest_number->target_number->above_median)
// 		rotate_both(a, b, cheapest_number, stack);
// 	else if (!(cheapest_number->above_median)
// 		&& !(cheapest_number->target_number->above_median))
// 		reverse_rotate_both(a, b, cheapest_number, stack);
// 	finish_rotation(b, cheapest_number, 'b', stack);
// 	finish_rotation(a, cheapest_number->target_number, 'a', stack);
// 	pa(stack);
// }

t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_number;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nb < smallest)
		{
			smallest = stack->nb;
			smallest_number = stack;
		}
		stack = stack->next;
	}
	return (smallest_number);
}

static void	set_target_number(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_number;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb
				&& current_a->nb < best_match_index)
			{
				best_match_index = current_a->nb;
				target_number = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_number = find_smallest(a);
		else
			b->target_number = target_number;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len_bigsort(a);
	len_b = stack_len_bigsort(b);
	while (b)
	{
		b->push_count = b->current_position;
		if (!(b->above_median))
			b->push_count = len_b - (b->current_position);
		if (b->target_number->above_median)
			b->push_count += b->target_number->current_position;
		else
			b->push_count += len_a - (b->target_number->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long			best_match_value;
	t_stack	*best_match_number;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_count < best_match_value)
		{
			best_match_value = b->push_count;
			best_match_number = b;
		}
		b = b->next;
	}
	best_match_number->cheapest = true;
}

void	init_numbers(t_stack *a, t_stack *b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target_number(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	bigsort(t_stack *stack)
{
	t_stack *a;
	t_stack	*b;
	// t_stack	*smallest;
	int		len_a;

	a = stack->a;
	b = stack->b;
	len_a = stack_len_bigsort(a);
	while (len_a-- > 5)
	{
		pb(stack);
	}
	tiny_sort_5(stack);
	// print_stack(stack->a, 1);
	// print_stack(stack->b, 2);
	while (b)
	{
		init_numbers(a, b);
		// move_price(a, b, stack);
	}
	set_current_pos(a);
	// smallest = find_smallest(a);
	// if (smallest->above_median)
	// 	while (a != smallest)
	// 		ra(stack);
	// else
	// 	while (a != smallest)
	// 		rra(stack);
}
