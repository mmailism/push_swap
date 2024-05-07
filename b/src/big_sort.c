// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   big_sort.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
// /*   Updated: 2024/05/07 19:59:47 by iammai           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "./../include/push_swap.h"

// int	ft_find_place_b(t_stack *stack_b, int nbr_push)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	i = 1;
// 	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
// 		i = 0;
// 	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
// 		i = ft_find_index(stack_b, ft_max(stack_b));
// 	else
// 	{
// 		tmp = stack_b->next;
// 		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
// 		{
// 			stack_b = stack_b->next;
// 						// print_stack(stack_a, 1);
// 		// print_stack(&stack_b, 2);tmp = stack_b->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// int	ft_find_place_a(t_stack *stack_a, int nbr_push)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	i = 1;
// 	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
// 		i = 0;
// 	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
// 		i = ft_find_index(stack_a, ft_min(stack_a));
// 	else
// 	{
// 		tmp = stack_a->next;
// 		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
// 		{
// 			stack_a = stack_a->next;
// 			tmp = stack_a->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// t_stack	*ft_sort_b(t_stack **stack_a)
// {
// 	t_stack	*stack_b;

// 	stack_b = NULL;
// 	if (stack_size(*stack_a) > 3 && !is_sort(*stack_a))
// 		pb(stack_a, &stack_b, 0);
// 	if (stack_size(*stack_a) > 3 && !is_sort(*stack_a))
// 		pb(stack_a, &stack_b, 0);
// 	if (stack_size(*stack_a) > 3 && !is_sort(*stack_a))
// 		ft_sort_b_till_3(stack_a, &stack_b);
// 	// printf("output after if :");
// 	// print_stack(stack_a, 1);
// 	// print_stack(&stack_b, 2);
// 	if (!is_sort(*stack_a))
// 		tiny_sort_3(stack_a);
// 	return (stack_b);
// }

// t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	while (*stack_b)
// 	{
// 		tmp = *stack_b;
// 		i = ft_rotate_type_ba(*stack_a, *stack_b);
// 		while (i >= 0)
// 		{
// 			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rarb(stack_a, stack_b, tmp->nbr, 'b');
// 			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rarrb(stack_a, stack_b, tmp->nbr, 'b');
// 			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
// 			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, tmp->nbr))
// 				i = ft_apply_rrarb(stack_a, stack_b, tmp->nbr, 'b');
// 			else
// 				tmp = tmp->next;
// 		}
// 	}
// 	return (stack_a);
// }

// void	push_swap(t_stack **stack_a)
// {
// 	t_stack	*stack_b;
// 	int		i;

// 	stack_b = NULL;
// 	stack_b = ft_sort_b(stack_a);
// 	stack_a = ft_sort_a(stack_a, &stack_b);
// 	i = ft_find_index(*stack_a, ft_min(*stack_a));
// 	if (i < stack_size(*stack_a) - i)
// 	{
// 		while ((*stack_a)->nbr != ft_min(*stack_a))
// 		{
// 			// print_stack(stack_a, 1);
// 			// print_stack(&stack_b, 2);
// 			ra(stack_a, 0);
// 		}
// 	}
// 	else
// 	{
// 		// printf("before rra\n");
// 		// print_stack(stack_a, 1);
// 		// print_stack(&stack_b, 2);
// 		while ((*stack_a)->nbr != ft_min(*stack_a))
// 		{
// 			rra(stack_a, 0);
// 			// printf("after rra\n");
// 			// print_stack(stack_a, 1);
// 			// print_stack(&stack_b, 2);
// 		}
// 	}
// }
