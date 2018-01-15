/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:44:12 by satkins           #+#    #+#             */
/*   Updated: 2018/01/15 03:19:04 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void			digitizer(t_list *num);
t_list			*subtract(t_bistro *bistro, t_list *oper1, t_list *oper2);
t_list			*addition(t_bistro *bistro, t_list *operand1, t_list *operand2);
int				check_size(t_list *oper1, t_list *oper2, t_bistro *b);
t_list			*modulo(t_bistro *bistro, t_list *oper1, t_list *oper2);
t_list			*division(t_bistro *bistro, t_list *oper1, t_list *oper2);

#endif
