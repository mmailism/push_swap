/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/09 20:30:45 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	check_error_syntax(char *tmp, t_stack *a)
{
	if (error_syntax(tmp))
	{
		ft_freestr(&tmp);
		free(tmp);
		error_free(a);
	}
}

t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	while (argv[++i] != NULL)
	{
		tmp = ft_split(argv[i], ' ');
		if (tmp[0] == NULL)
			error_free(a);
		j = -1;
		while (tmp[++j] != NULL)
		{
			check_error_syntax(tmp[j], a);
			stack_add_back(&a, stack_new(atoi_pushswap(tmp[j], a)));
		}
		free_split(tmp);
	}
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
	{
		free(a);
		exit (0);
	}
	else
		a = ft_sub_process(argv);
	return (a);
}

static int	ft_checkdup(t_stack *a)
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

void	ft_sorting(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_size(*stack_a) == 2)
		sa(stack_a, 0);
	else if (stack_size(*stack_a) == 3)
		tiny_sort_3(stack_a);
	else if (stack_size(*stack_a) == 4)
		tiny_sort_4(stack_a, &stack_b);
	else if (stack_size(*stack_a) == 5)
		tiny_sort_5(stack_a, &stack_b);
	else
		pushswap(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_process(argc, argv);
	if (!stack_a || ft_checkdup(stack_a))
		error_free(stack_a);
	if (!is_sort(stack_a))
		ft_sorting(&stack_a);
	free_stack(stack_a);
}
