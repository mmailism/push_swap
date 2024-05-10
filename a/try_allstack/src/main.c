/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/05 19:07:23 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

//! comment
//? comment
//* comment

int	is_sort(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
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

t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
	{
		j = atoi_pushswap(tmp[i]);
		stack_add_back(&a, stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		error_free(a);
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = atoi_pushswap(argv[i]);
			stack_add_back(&a, stack_new(j));
			i++;
		}
	}
	return (a);
}

int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

int	stack_size(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_sorting(t_stack **stack_a)
{
	t_stack	*stack_b;
	// int		i;

	stack_b = NULL;
	if (stack_size(*stack_a) == 2)
		sa(stack_a, 0);
	else if (stack_size(*stack_a) == 3)
		tiny_sort_3(stack_a);
	// else if (stack_size(*stack_a) == 4)
		// tiny_sort_4(stack_a, &stack_b);
	else if (stack_size(*stack_a) == 5)
		tiny_sort_5(stack_a, &stack_b);
	else
		push_swap(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_process(argc, argv);
	if (!stack_a || ft_checkdup(stack_a))
		error_free(stack_a);
	// if (!ft_checksorted(stack_a))
	// 	ft_sort(&stack_a);
	// if (argc > 1)
	// {
	// 	stack_a = stack_init(argc, argv);
	if (!is_sort(stack_a))
		ft_sorting(&stack_a);
	else
		return (0);
	// printf("%ld\n", stack_a->nbr);
	free_data(stack_a);
}
