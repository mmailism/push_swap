/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/03 17:41:24 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	convert_nb(char *str_nbr, t_list *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
	if (*str_nbr == '\0')
		error_free(stack);
	if (*str_nbr == '+' || *str_nbr == '-')
	{
		if (*(str_nbr + 1) < '0' || *(str_nbr + 1) > '9')
			error_free(stack);
		if (*str_nbr == '-')
			neg = -1;
		str_nbr++;
	}
	while (*str_nbr)
	{
		if ((*str_nbr < '0' || *str_nbr > '9'))
			error_free(stack);
		res = (*str_nbr - '0') + (res * 10);
		if ((res * neg) < INT_MIN || (res * neg) > INT_MAX)
			error_free(stack);
		str_nbr++;
	}
	return ((int)(res * neg));
}

void	check_dup(int nb, t_list *stack)
{
	t_stack	*head_stack;

	if (!stack->a)
		return ;
	head_stack = stack->a;
	while (head_stack)
	{
		if (nb == head_stack->nb)
			error_free(stack);
		head_stack = head_stack->next;
	}
}

t_stack	*alloc_stack(t_list *lst, t_stack *stack, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_free(lst);
	new->nb = nb;
	// new->sort = 0;
	new->next = stack;
	stack = new;
	return (new);
}

int	stack_size(t_list *stack, char name)
{
	int		size;
	t_stack	*current;

	size = 0;
	if (name == 'a')
		current = stack->a;
	else
		current = stack->b;
	while (current->next)
	{
		size++;
		current = current->next;
		if (!current->next)
			size++;
	}
	return (size);
}

t_list	*find_last_node_a(t_list *head)
{
	if (head == NULL)
		return (NULL);
	while (head->a->next)
		head->a->last = head->a->next;
	return (head);
}
