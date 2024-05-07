// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   big_sort_utils.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
// /*   Updated: 2024/05/06 15:32:02 by iammai           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "./../include/push_swap.h"

// void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	while (stack_size(*stack_a) > 3 && !is_sort(*stack_a))
// 	{
// 		tmp = *stack_a;
// 		i = ft_rotate_type_ab(*stack_a, *stack_b);
// 		while (i >= 0)
// 		{
// 			if (i == ft_case_rarb(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rarb(stack_a, stack_b, tmp->nbr, 'a');
// 			else if (i == ft_case_rrarrb(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
// 			else if (i == ft_case_rarrb(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rarrb(stack_a, stack_b, tmp->nbr, 'a');
// 			else if (i == ft_case_rrarb(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rrarb(stack_a, stack_b, tmp->nbr, 'a');
// 			else
// 				tmp = tmp->next;
// 		}
// 	}
// }

// int	ft_min(t_stack *a)
// {
// 	int		i;

// 	i = a->nbr;
// 	while (a)
// 	{
// 		if (a->nbr < i)
// 			i = a->nbr;
// 		a = a->next;
// 	}
// 	return (i);
// }

// int	ft_max(t_stack *a)
// {
// 	int		i;

// 	i = a->nbr;
// 	while (a)
// 	{
// 		if (a->nbr > i)
// 			i = a->nbr;
// 		a = a->next;
// 	}
// 	return (i);
// }

// int	ft_find_index(t_stack *a, int nbr)
// {
// 	int		i;

// 	i = 0;
// 	while (a->nbr != nbr)
// 	{
// 		i++;
// 		a = a->next;
// 	}
// 	a->index = 0;
// 	return (i);
// }
