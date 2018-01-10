#ifndef BISTRO_H

# define BISTRO_H

# include "libft.h"

typedef struct	s_bistro
{
	char		*base;
	int			base_size;
	char		*exp;
	int			exp_size;
	t_stack		*operator_stack;
	t_queue		*operand_queue;
}				t_bistro;

#endif