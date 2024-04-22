/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:26 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*get_bottom(t_stack *a, t_stack *new)
// {
// 	if (a && new)
// 	{
// 		new->next = a;
// 		a = new;
// 	}
//     return (a);
// }

// t_stack	*stack_init(t_stack *a, t_stack *new)
// {
// 	t_stack	*top;

// 	if (!new)
// 		return (NULL);
// 	if (!a)
// 	{
// 		a = new;
// 		return (NULL);
// 	}
// 	top = get_bottom(a, new);
// 	top->next = new;
// 	return (top);
// 	// This 'top' variable has asign but doesn't use
// 	// So we have to return adress top
// 	// return (top)
// }

// void	*stack_add(t_stack *stack, t_stack *new)
// {
// 	t_stack	*tmp;

//     tmp = stack_last(stack);
// 	if (tmp == NULL)
// 		tmp = new;
// 	else
// 		tmp->next = new;
// }

// t_stack	*stack_last(t_stack *lst)
// {
// 	if (!lst)
// 		return (lst);
// 	while (lst->next != 0)
// 		lst = lst->next;
// 	return (lst);
// }

// t_stack *stack_new(int *new)
// {
// 	t_stack	*list;

// 	list = malloc(sizeof(t_stack));
// 	if (!list)
// 		return (NULL);
// 	list->content = *new;
// 	list->next = NULL;
// 	return (list);
// }

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
