#ifndef BISTRO_H

# define BISTRO_H

# include "libft.h"

typedef struct	s_bistro
{
	char		*base;
	int			base_size;
	char		*exp;
	int			exp_size;
	t_stack		*stack;
}				t_bistro;

#endif