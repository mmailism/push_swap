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

// void	*free_exit(t_list **a, int mem)
// {
// 	if (mem == 1)
// 	{
// 		free(a);
// 		exit(0);
// 	}
// 	if (mem == 2)
// 	{
// 		if (a == NULL || a != NULL)
// 			free(a);
// 		write(2, "Error\n", 6);
// 		exit (0);
// 	}
// }

// void	input_is_correct(char **param)
// {
// }
t_stack	stack_add(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = ft_lstlast(*(stack));
		tmp->next = new;
	}
}

t_stack *stack_new(t_stack **new)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return ;
	list->content = new;
	list->next = '\0';
	return (list);
}

void	get_numbers(char *av, t_stack **stack_a)
{
	char		**param;
	long int	n;
	int			i;

	param = ft_split(av, ' ');
	i = 0;
	while (param[i] != NULL)
	{
		if (param[i] != NULL/*input_is_correct(param[i])*/)
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
			{
				return (free(stack_a), NULL);
				// error_exit(stack_a, NULL);
			}
			stack_add(stack_a, stack_new(n));
		}
		else
		{
			return ;
			// error_exit(NULL, NULL);
		}
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
			nbr = ft_atoi(tmp[i]);
			if (n > INT_MAX || n < INT_MIN)
				return (free(tmp), NULL);
			a = stack_init(a, ft_lstnew(nbr));
		}
		else
			return (free(tmp), NULL);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

t_stack	**stack_init(t_stack **a, t_stack **new)
{
	t_list	*top;

	if (!new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	top = get_bottom(*a);
	top->next = new;
	return (top);
	// This 'top' variable has asign but doesn't use
	// So we have to return adress top
	// return (top)
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int i;

	a = NULL;
	b = NULL;
	i = 1;
	while (i < argc)
	{
		get_numbers(argv[i], &a);
		i++;
	}
	printf("here %d", i);
	// if (!stack_sort(a))
	// {
	// 	if (stack_sort(a) == 2)
	// 		sa(&a, false)
	// }
	return (0);
}
