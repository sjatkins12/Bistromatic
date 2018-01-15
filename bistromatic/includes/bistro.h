/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:44:12 by satkins           #+#    #+#             */
/*   Updated: 2018/01/14 16:44:43 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
t_list	*subtract(t_bistro *bistro, t_list *oper1, t_list *oper2);
t_list	*addition(t_bistro *bistro, t_list *operand1, t_list *operand2);
int		check_size(t_list *oper1, t_list *oper2, t_bistro *b);
t_stack				*init_stack(void);
t_queue				*init_queue(void);
void				ft_enqueue(t_queue *queue, void *content, size_t c_size);
void				*ft_dequeue(t_queue *queue);
int					isEmpty(t_queue *queue);
void 				*peek_queue(t_queue *queue);
void				ft_stackpush(t_stack *stack, void *content, size_t c_size);
void				*ft_stackpop(t_stack *stack);
void				*ft_stackpeak(t_stack *stack);
int					isempty_stack(t_stack *stack);

#endif
