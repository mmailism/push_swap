/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/03 17:45:23 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

//! comment
//? comment
//* comment

static t_list	*alloc_list(void)
{
	t_list	*stack;

	stack = NULL;
	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		error_free(NULL);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

t_list	*stack_init(int argc, char **argv)
{
	t_list	*new;

	new = alloc_list();
	add_data(new, argc, argv);
	return (new);
}

static void	pos_init(t_list *stack)
{
	stack->top_a = stack->a;
	stack->bottom_a = bottom_stack(stack->a);
	stack->top_b = NULL;
	stack->bottom_b = NULL;
}

bool	is_sort(t_list *ref)
{
	t_stack	*current;

	current = ref->a;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb))
			return (false);
		current = current->next;
	}
	return (true);
}

void	start_init(int argc, char **argv, t_list *stack)
{
	if (argc > 1)
	{
		stack = stack_init(argc, argv);
		// a = stack_init(argc, argv);
		// b = stack_init(argc, argv);
		pos_init(stack);
	}
}
//! now crreate big sort

int	main(int argc, char **argv)
{
	t_list	*stack;
	// t_stack	*a;
	// t_stack	*b;

	// a = NULL;
	// b = NULL;
	stack = NULL;
	if (argc > 1)
	{
		stack = stack_init(argc, argv);
		if (!is_sort(stack))
		{
			if (stack_len(stack) < 2)
				sa(stack);
			else if (stack_len(stack) < 3)
				tiny_sort_3(stack);
			else if (stack_len(stack) < 4)
				tiny_sort_4(stack);
			else if (stack_len(stack) < 5)
				tiny_sort_5(stack);
			else
				many_big_sort(stack);
		}
		print_stack(stack->a, 1);
		free_data(stack);
	}
}
