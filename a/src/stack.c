/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	stack_len(t_list *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = stack->a;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

static int	count_elements(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

static char	**split_to_stack(t_list *stack, char *str)
{
	char	**data;
	char	*temp;
	int		num_elements;
	int		start;
	int		end;

	data = ft_split(str, ' ');
	if (!data)
		error_free(stack);
	num_elements = count_elements(data);
	start = 0;
	end = num_elements - 1;
	while (start < end)
	{
		temp = data[start];
		data[start] = data[end];
		data[end] = temp;
		start++;
		end--;
	}
	return (data);
}

void	add_data(t_list *stack, int argc, char **argv)
{
	int		nb;
	char	**data;
	char	**head;

	argc--;
	while (argc > 0)
	{
		data = split_to_stack(stack, argv[argc]);
		head = data;
		while (*head)
		{
			nb = convert_nb(*head, stack);
			check_dup(nb, stack);
			stack->a = alloc_stack(stack, stack->a, nb);
			head++;
		}
		data = free_split(data);
		argc--;
	}
}

t_stack	*bottom_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}
