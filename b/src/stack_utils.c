/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/09 19:09:56 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	error_syntax(char *str_nbr)
{
	if (*str_nbr == ' ')
		return (1);
	if (!(*str_nbr == '+' || *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	atoi_pushswap(char *str, t_stack *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
	if (*str == '\0')
		error_free(stack);
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) < '0' || *(str + 1) > '9')
			error_free(stack);
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9'))
			error_free(stack);
		res = (*str - '0') + (res * 10);
		if ((res * neg) < INT_MIN || (res * neg) > INT_MAX)
			error_free(stack);
		str++;
	}
	return ((int)(res * neg));
}
