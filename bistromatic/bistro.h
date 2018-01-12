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

typedef struct	s_operand
{
	char		c;
	int			negative;
}				t_operand;

void	digitizer(t_list *num);
#endif