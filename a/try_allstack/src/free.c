/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/05 16:26:54 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_data(t_stack *stack)
{
	if (stack)
	{
		free_stack(stack);
	}
}

void	error_free(t_stack *stack)
{
	free_data(stack);
	write(2, "Error\n", 6);
	exit(1);
}

char	**free_split(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	return (NULL);
}

void	print_stack(t_stack **stack, int mode)
{
	if (mode == 1)
	{
		printf("stack A: ");
		while (stack != NULL)
		{
			printf("%ld ", (*stack)->nbr);
			*stack = (*stack)->next;
		}
		printf("\n");
	}
	if (mode == 2)
	{
		printf("stack B: ");
		while (stack != NULL)
		{
			printf("%ld ", (*stack)->nbr);
			*stack = (*stack)->next;
		}
		printf("\n");
	}
}
