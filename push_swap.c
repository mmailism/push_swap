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

// void	*free_exit(t_list **a, t_list **b, int mem)
// {
// 	if (mem == 1)
// 	{
// 		free(a);
// 		free(b);
// 		exit(0);
// 	}
// 	if (mem == 2)
// 	{
// 		if (a == NULL || a != NULL)
// 			free(a);
// 		if (b == NULL || b != NULL)
// 			free(b);
// 		write(2, "Error\n", 6);
// 		exit (0);
// 	}
// }

t_list	**stack_init(t_list **a, char **argv, int argc)
{
	t_list	*tmp;
	int		i;
	long	nbr;

	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN /*|| ft_check(nbr, argv[i]) == 0*/)
		{
			free(a);
			free(argv);
			free(tmp);
			exit(0);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(a, tmp);
		i++;
	}
	return(a);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	if (!a)
		return (-1);
	if (argc == 1 || (argc == 2 && !argv[1][0]) || argc > 2)
		return(0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	printf("here %p", a);
	// if (!stack_sort(a))
	// {
	// 	if (stack_sort(a) == 2)
	// 		sa(&a, false)
	// }
	return (0);
}
