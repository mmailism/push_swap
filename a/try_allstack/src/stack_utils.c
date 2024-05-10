/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:46:22 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/05 02:41:45 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	convert_nb(char *str_nbr, t_stack *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
	if (*str_nbr == '\0')
		error_free(stack);
	if (*str_nbr == '+' || *str_nbr == '-')
	{
		if (*(str_nbr + 1) < '0' || *(str_nbr + 1) > '9')
			error_free(stack);
		if (*str_nbr == '-')
			neg = -1;
		str_nbr++;
	}
	while (*str_nbr)
	{
		if ((*str_nbr < '0' || *str_nbr > '9'))
			error_free(stack);
		res = (*str_nbr - '0') + (res * 10);
		if ((res * neg) < INT_MIN || (res * neg) > INT_MAX)
			error_free(stack);
		str_nbr++;
	}
	return ((int)(res * neg));
}
