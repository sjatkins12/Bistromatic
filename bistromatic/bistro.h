#ifndef BISTRO_H

# define BISTRO_H

# include "libft/libft.h"

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
t_list	*subtract(t_bistro *bistro, t_list *oper1, t_list *oper2);
t_list	*addition(t_bistro *bistro, t_list *operand1, t_list *operand2);
int		check_size(t_list *oper1, t_list *oper2, t_bistro *b);

#endif
