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
    int				nbr;
    int				index;
    struct s_stack	*next;
    struct s_stack	*prev;
}					t_stack;

#endif