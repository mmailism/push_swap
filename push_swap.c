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

#include "include/push_swap.h"

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static int	arg_is_num(char **argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_num(argv[i]))
			return (0);
		nbr += arg_zero(argv[i]);
		i+=;
	}
	if (nbr >1)
		return (0);
	if (have_dup(argv))
		return(0);
	return (1);	
}

void	print_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_lstclear(stack_a, NULL);
	if (stack_b == NULL || *stack_b != NULL)
		ft_lstclear(stack_b, NULL);
	write(2, "Error\n", 6);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (!stack_a || argc < 2)
		return(0);
	if (!is_correct_input(argv))
		print_errorr(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	if (!ft_checksort(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}