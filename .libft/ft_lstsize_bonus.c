/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:28:04 by kpueankl          #+#    #+#             */
/*   Updated: 2023/08/25 15:28:06 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_lstsize(t_list *lst)
{
	long int		len;
	t_list			*tmp;

	len = 0;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp->next != 0)
	{
		tmp = tmp->next;
		len++;
	}
	if (tmp->next == 0)
		len++;
	return (len);
}
