/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:19:07 by kpueankl          #+#    #+#             */
/*   Updated: 2024/05/05 02:31:39 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

static void	write_error(void)
{
	write(1, "Erorr\n", 6);
	exit(1);
}

int	atoi_pushswap(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			write_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		write_error();
	return (mod * i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;
	size_t			j;

	i = s;
	j = 0;
	if (n == 0)
		return ;
	while (j < n)
	{
		i[j] = 0;
		j++;
	}
}

void	*ft_calloc(size_t count, size_t n)
{
	void	*alt;

	alt = (void *)malloc(count * n);
	if (alt == NULL)
		return (NULL);
	ft_bzero(alt, (count * n));
	return (alt);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static char	*al_word(const char *str, int start, int end)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (start < end)
	{
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = 0;
	return (dst);
}

static int	word_count(const char *str, char n)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*str)
	{
		if (*str != n && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == n)
			i = 0;
		str++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	ft_numalt(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**altw;
	size_t	i;
	int		j;
	int		s_word;

	ft_numalt(&i, &j, &s_word);
	altw = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!altw || !s)
		return (NULL);
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			altw[j] = al_word(s, s_word, i);
			if (!(altw[j]))
				return (ft_free(altw, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (altw);
}
