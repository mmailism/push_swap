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

#include "./../include/push_swap.h"

t_list	*find_last_node_a(t_list *head)
{
	if (head == NULL)
		return (NULL);
	while (head->a->next)
		head->a->last = head->a->next;
	return (head);
}

t_list	*alloc_list(void)
{
	t_list *stack;

	stack = NULL;
	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		error_free(NULL);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

int	convert_nb(char *str_nbr, t_list *stack)
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

static int	count_elements(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

static char	**split_to_stack(t_list *stack, char *str)
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

void	check_dup(int nb, t_list *stack)
{
	t_stack	*head_stack;

	if (!stack->a)
		return ;
	head_stack = stack->a;
	while (head_stack)
	{
		if (nb == head_stack->nb)
			error_free(stack);
		head_stack = head_stack->next;
	}
}

t_stack	*alloc_stack(t_list *lst, t_stack *stack, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_free(lst);
	new->nb = nb;
	new->sort = 0;
	new->next = stack;
	stack = new;
	return (new);
}

int	stack_size(t_list *stack, char name)
{
	int		size;
	t_stack	*current;

	size = 0;
	if (name == 'a')
		current = stack->a;
	else
		current = stack->b;
	while (current->next)
	{
		size++;
		current = current->next;
		if (!current->next)
			size++;
	}
	return (size);
}

void	add_data(t_list *stack, int argc, char **argv)
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
	// stack->t_size = stack_size(stack, 'a');
}

t_list	*stack_init(int argc, char **argv)
{
	t_list	*new;

	new = alloc_list();
	add_data(new, argc, argv);
	return (new);
}

t_stack	*bottom_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

static void	pos_init(t_list *stack)
{
	stack->top_a = stack->a;
	stack->bottom_a = bottom_stack(stack->a);
	stack->top_b = NULL;
	stack->bottom_b = NULL;
}

static bool	is_sort(t_list *ref)
{
	t_stack	*current;

	current = ref->a;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb))
			return (false);
		current = current->next;
	}
	return (true);
}

int	stack_len(t_list *stack)
{
	int	count;
	t_stack	*current;

	count = 0;
	current = stack->a;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	show_output(char *str, int show)
{
	if (show == 0)
		return (1);
	if (printf("%s", str) == -1)
		return (-1);
	return (1);
}

void	ra(t_list *stack)
{
	t_stack	*head;
	t_stack	*curr;

		print_stack(stack->a, 1);
		print_stack(stack->b, 2);
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	head = stack->a->next;
	curr = stack->a;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = stack->a;
	stack->a->next = NULL;
	stack->a = head;
		print_stack(stack->a, 1);
		print_stack(stack->b, 2);
	printf("ra\n");

	// if (show_output("ra\n", stack->show_output) == -1)
	// 		return ;
		// error_free(stack);
}

void	tiny_sort_2(t_list *stack)
{
	t_list	*curr;

	curr = stack;
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	if (curr)
	{
		if ((curr->a) > (curr->a->next))
		{
			if (curr->a > curr->a->next)
				ss(stack);
			else
				return ;
		}
	}
}

// t_list	*find_highest(t_list *stack)
// {
// 	int				highest;
// 	t_list		*highest_node;

// 	// if (stack == NULL)
// 		// return (NULL);
// 	highest = INT_MIN;
// 	while (stack)
// 	{
// 		if (stack->a->nb > highest)
// 		{
// 			highest = stack->a->nb;
// 			highest_node = stack;
// 		}
// 		stack->a = stack->a->next;
// 	}
// 	return (highest_node);
// }

void tiny_sort_3(t_list *stack) 
{
    if (stack->a != NULL) 
	{
        if (stack->a->nb > stack->a->next->nb)
            sa(stack);

		t_list	*last = find_last_node_a(stack);
			exit(0);
        if (stack->a->nb > last->a->nb)
		{
            print_stack(stack->a, 1);
            print_stack(stack->b, 2);
            ra(stack);
        } 
		else 
            return;
    }
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	if (argc > 1)
	{
		stack = stack_init(argc, argv);
		pos_init(stack);
		stack->show_output = 1;
		if (!is_sort(stack))
		{
			if (stack_len(stack) < 2)
			{
				tiny_sort_2(stack);
			}
			else if (stack_len(stack) < 3)
			{
				// tiny_sort_3(stack);
			// else
			// 	push_swap(stack);
			}
			// else 
				// push_swap(stack);
		}
		free_data(stack);
	}
}
