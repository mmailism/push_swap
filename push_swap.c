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

int	ft_atoi(const char *str)
{
	unsigned int	num;
	signed char		sign;
	size_t			i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (! (48 <= str[i] && str[i] <= 57))
			return (num * sign);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

void	get_numbers(char *av, t_stack *stack_a)
{
	char		**param;
	int			n;
	int			i;

	param = ft_split(av, ' ');
	i = 0;
	while (param[i] != NULL)
	{
		if (param[i] != NULL/* && input_is_correct(param[i])*/)
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
			{
				free(param);
				exit(0);
				// error_exit(stack_a, NULL);
			}
			stack_add(stack_a, stack_new(&n));
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

// t_stack	*get_num(char **argv, t_stack *a)
// {
// 	char		**tmp;
// 	int			i;
// 	long		nbr;

// 	tmp = ft_split(*argv, ' ');
// 	i = 0;
// 	while (tmp[i] != NULL)
// 	{
// 		if (tmp[i]/*input_correct(tmp[i])*/)
// 		{
// 			nbr = ft_atoi(tmp[i]);
// 			if (nbr > INT_MAX || nbr < INT_MIN)
// 				return (free(tmp), NULL);
// 			a = stack_init(&a, stack_new(&nbr));
// 		}
// 		else
// 			return (free(tmp), NULL);
// 		free(tmp[i]);
// 		i++;
// 	}
// 	free(tmp);
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;
	int i;

	a = NULL;
	// b = NULL;
	i = 1;
	while (i < argc)
	{
		get_numbers(argv[i], a);
		i++;
	}
	printf("here %d", i);
	return (0);
}
