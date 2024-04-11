#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				next;
	int				max;
	int				min;
	int				mid;
	int				flag;
	t_list			*stack_a;
	t_list			*stack_b;
	int				a_size
	int				b_size;
}					t_stack;

#endif