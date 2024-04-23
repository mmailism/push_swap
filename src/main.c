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

void print_stack(t_stack *stack, int mode) 
{
	if (mode == 1)
	{
    	printf("stack A: ");
    	while (stack != NULL) {
    	    printf("%d ", stack->nb);
    	    stack = stack->next;
    	}
    	printf("\n");
	}
	if (mode == 2)
	{
    	printf("stack B: ");
    	while (stack != NULL) {
    	    printf("%d ", stack->nb);
    	    stack = stack->next;
    	}
    	printf("\n");
	}
}

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

void	free_data(t_list *stack)
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

void	error_free(t_list *stack)
{
	free_data(stack);
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
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

char	**free_split(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	return (NULL);
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

//!now//
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
	stack->t_size = stack_size(stack, 'a');
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
	stack->size_a = stack->t_size;
	stack->size_b = 0;
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

void	sa_sb(t_list *stack)
{
	int	tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a->next->nb;
			print_stack(stack->a, 1);
		stack->a->next->nb = stack->a->nb;
			print_stack(stack->a, 1);
		stack->a->nb = tmp;
			print_stack(stack->a, 1);
		if (show_output("sa\n", stack->show_output) == -1)
			error_free(stack);
		// stack->top_a = stack->a;
		// if (stack->size_a == 2)
		// 	stack->bottom_a = stack->a->next;
	}
	else if (stack->b && stack->b->next)
	{
		tmp = stack->b->next->nb;
		stack->b->next->nb = stack->b->nb;
		stack->b->nb = tmp;
		if (show_output("sb\n", stack->show_output) == -1)
			error_free(stack);
		stack->top_b = stack->b;
	}
	else
		return ;
}

void	pa(t_list *stack)
{
	t_stack *tmp;

	if (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		tmp->next = stack->b;
        stack->b = tmp;
			print_stack(stack->a, 1);
			print_stack(stack->b, 2);
		if (show_output("pa\n", stack->show_output) == -1)
            error_free(stack);
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
			if (stack_len(stack) == 2)
			{
				sa_sb(stack);
			}
			else if (stack_len(stack) == 3)
			{
				pa(stack);
			// 	tiny_sort(stack);
			// else
			// 	push_swap(stack);
			}
		}
		free_data(stack);
	}
}
