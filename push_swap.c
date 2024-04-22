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

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_data(t_stack *stack)
{
	if(stack)
	{
		if (stack->tmp)
			free_stack(stack->tmp);
		if (stack->a)
			free_stack(stack->a);
		if (stack->b)
			free_stack(stack->b);
		free(stack);
	}
}

void	error_free(t_stack *stack)
{
	free_data(stack);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr >= '0' && str_nbr <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->content = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*alloc_list(void)
{
	t_stack *stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_free(NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	return (stack);
}

static int	count_elements(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

static char	**split_to_stack(t_stack *stack, char *str)
{
	char	**data;
	char	*temp;
	int		num_elements;
	int		start;
	int		end;

	data = ft_split(str, ' ');
	if (!data)
		error_free(stack);
	num_elements = count_elements(data);
	start = 0;
	end = num_elements - 1;
	while (start < end)
	{
		temp = data[start];
		data[start] = data[end];
		data[end] = temp;
		start++;
		end--;
	}
	return (data);
}

void	add_data(t_stack *stack, int argc, char **argv)
{
	int		nb;
	char	**data;
	char	**head;

	argc--;
	while (argc > 0)
	{
		data = split_to_stack(stack, argv[argc]);
		head = data;
		while (*head)
		{
			nb = convert_nb(*head, stack);
			check_dup(nb, stack);
			stack->a = alloc_stack(stack, stack->a, nb);
			head++;
		}
		data = free_split(data);
		argc--;
	}
	stack->t_size = stack_size(stack, 'a');
}

t_stack	*stack_init(int argc, char **argv)
{
	t_stack	*new;

	new = alloc_list();
	add_data(new, argc, argv);
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc > 1)
	{
		stack = stack_init(argc, argv);
		position_init(stack);
		stack->output
	}
}