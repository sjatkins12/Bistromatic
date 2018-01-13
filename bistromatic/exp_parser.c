/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:17:36 by satkins           #+#    #+#             */
/*   Updated: 2018/01/12 17:36:27 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

static void	check_oop(char c, t_bistro *bistro)
{
	char	*top;

	if (!is_opperator(c))
		return ;
	top = ft_stackpeak(bistro->operator_stack);
	if (!top || (*top == '(' && c != ')'))
		ft_stackpush(&(bistro->operator_stack), creat_node(c));
	else if (c == ')')
	{
		while (top && *top != '(')
			ft_queueadd(&(bistro->operand_queue),
				(top = ft_stackpop(&(bistro->operator_stack))));
		ft_stackpop(&(bistro->operator_stack));
	}
	else if ((*top == '-' || *top == '+') && !(c == '+' || c == '-'))
		ft_stackpush(&(bistro->operator_stack), creat_node(c));
	else
	{
		ft_enqueue(&(bistro->operand_queue), top);
		ft_stackpop(&(bistro->operator_stack));
	}
}

static int	is_base(char c, t_bistro *bistro)
{
	int		i;

	i = -1;
	while (++i < bistro->base_size)
	{
		if (c == bistro->base[i])
			return (1);
	}
	return (0);
}

void		split_operand(t_bistro *bistro)
{
	int		i;
	int		j;
	t_list	*head;

	i = -1;
	head = NULL;
	while (++i < bistro->exp_size)
	{
		if (is_base(bistro->exp[i], bistro))
		{
			--i;
			while (is_base(bistro->exp[i]))
				ft_lstadd(&head, ft_lstnew(&(bistro->exp[i]), 1));
			ft_enqueue(&(bistro->operand_queue), head);
			head = NULL;
		}
		else
			check_oop(bistro->exp[i], bistro);
	}
}
