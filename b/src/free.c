/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   free.c			:+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: iammai <iammai@student.42.fr>		+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2023/08/25 15:19:07 by kpueankl		#+#  #+#		  */
/*   Updated: 2024/05/08 23:53:14 by iammai	 ###   ########.fr	*/
/*									  */
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
	t_stack	*temp;

	temp = *stack;
	if (mode == 1)
	{
		printf("stack A: ");
		while (temp != NULL)
		{
			printf("%ld ", temp->nbr);
			temp = temp->next;
		}
		printf("\n");
	}
	else if (mode == 2)
	{
		printf("stack B: ");
		while (temp != NULL)
		{
			printf("%ld ", temp->nbr);
			temp = temp->next;
		}
		printf("\n");
	}
}

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}
