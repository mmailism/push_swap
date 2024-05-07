/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/06 13:19:10 by iammai           ###   ########.fr       */
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

void	error_free(t_stack *stack)
{
	free_stack(stack);
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
    t_stack *temp = *stack; // Create a temporary pointer to iterate over the stack
    
    if (mode == 1)
    {
        printf("stack A: ");
        while (temp != NULL) // Iterate using temp, not stack
        {
            printf("%ld ", temp->nbr);
            temp = temp->next; // Move to the next node
        }
        printf("\n");
    }
    else if (mode == 2) // Changed to else if to ensure only one block is executed
    {
        printf("stack B: ");
        while (temp != NULL) // Iterate using temp, not stack
        {
            printf("%ld ", temp->nbr);
            temp = temp->next; // Move to the next node
        }
        printf("\n");
    }
    // No need for else, as the function ends here if mode is neither 1 nor 2
}
