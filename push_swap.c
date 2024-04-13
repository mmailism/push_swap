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

void	*free_exit(t_list **a, int mem)
{
	if (mem == 1)
	{
		free(a);
		exit(0);
	}
	if (mem == 2)
	{
		if (a == NULL || a != NULL)
			free(a);
		write(2, "Error\n", 6);
		exit (0);
	}
}

void	get_numbers(char *av, t_stack **stack_a)
{
	char		**param;
	long int	n;
	int			i;

	param = ft_split(av, ' ');
	i = 0;
	while (param[i] != '\0')
	{
		if (input_is_correct(param[i]))
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
				error_exit(stack_a, NULL);
			stack_add(stack_a, stack_new(n));
		}
		else
			error_exit(NULL, NULL);
		free(param[i]);
		i++;
	}
	free(param);
}

t_list	**get_num(char **argv, t_list **a)
{
	char	**tmp;
	int		i;
	long	nbr;

	tmp = ft_split(argv, ' ');
	i = 0;
	while (tmp[i] != '\0')
	{
		if (input_correct(tmp[i]))
		{
			n = ft_atoi(tmp[i]);
			if (n > INT_MAX || n < INT_MIN)
				free_exit(a, 2);
			stack_init(a, ft_lstnew(nbr));
		}
		else
			free_exit(a, 2);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

t_list	**stack_init(t_list **a, t_list **new)
{
	t_list	*top;

	if (!new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	top = ft_lstadd_front(*a);
	top->next = new;
}

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b
	int i;

	a = NULL;
	b = NULL;
	i= 1;
	while (i < argc)
	{
		get_numbers(argv[i], &a);
		i++;
	}
	stack_init(&a, argv + 1, argc == 2);
	printf("here %p", a);
	// if (!stack_sort(a))
	// {
	// 	if (stack_sort(a) == 2)
	// 		sa(&a, false)
	// }
	return (0);
}
