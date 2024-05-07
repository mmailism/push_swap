/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/08 02:22:38 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int find_max(t_stack *head) {
    if (head == NULL) {
        // fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }

    int max = head->nbr;
    t_stack *current = head->next;

    while (current != NULL) {
        if (current->nbr > max) {
            max = current->nbr;
        }
        current = current->next;
    }
    return max;
}

int find_min(t_stack *head) 
{
    int	min;
	t_stack *current;

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

int find_mid(int min, int max)
{
	int mid;
	
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

// void findLastNode(t_stack *head) 
// {
//     while (head->next != NULL)
//         head = head->next;
// 	return (head);
// }

// void	ft_push_to_a(t_stack **a, t_stack **b)
// {
// 	t_stack	*last;
// 	// int i;
	
// 	last = NULL;
// 	while ((*b)->next != NULL)
//         last = (*b)->next;
// 	if ((*b)->nbr == find_max(*b))
// 		pb(a, b, 0);
// 	else if (last)
// 		printf("here");
// 	else
// 		rb(b, 0);
// 		// return ;
// 	print_stack(&last, 2);
// 	print_stack(a, 1);
// 	print_stack(b, 2);
// }

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		length;
	int		i;
	int		j;
	int		max;
	t_stack	*copy;

	copy = *stack_b;
	length = stack_size(*stack_b);
	j = 0;
	i = 0;
	max = find_max(copy);
	i = find_max_i(copy, max);
	if (i < length / 2)
	{
		while (j++ < i)
			rb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	else
	{
		while (i++ < length - 1)
			rrb(stack_b, 0);
		rrb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	mid;
	
	i = 0;
	mid = stack_size(*stack_a) / 5;
	if (stack_size(*stack_a) > 100)
		mid = stack_size(*stack_a) / 10;
	while (*stack_a)
	{
		if ((*stack_a)->nbr <= i)
		{
			pb(stack_a, stack_b, 0);
			if (stack_size(*stack_b) > 3 && (*stack_b)->nbr < (*stack_b)->next->nbr)
				sb(stack_b, 0);
			i += 1;
		}
		else if ((*stack_a)->nbr <= (i + mid))
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i += 1;
		}
		else
			ra(stack_a, 0);
	}
}

void	pushswap_try(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!is_sort(*stack_a))
		ft_push_b(stack_a, &stack_b);
	while (stack_b)
		sort_b_to_a(stack_a, &stack_b);
	free(stack_b);
}
