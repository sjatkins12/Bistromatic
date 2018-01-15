/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:32:21 by satkins           #+#    #+#             */
/*   Updated: 2018/01/14 15:31:09 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

static int	get_val(char *c, t_bistro *bistro)
{
	int		i;

	i = -1;
	while (++i < bistro->base_size)
		if (*c == bistro->base[i])
			return (i);
	return (-1);
}
/*

*/
int			check_size(t_list *oper1, t_list *oper2, t_bistro *b)
{
	int		max;
	int		val1;
	int		val2;

	max = 1;
	while (oper1 && oper2)
	{
		val1 = get_val(oper1->content, b);
		val2 = get_val(oper2->content, b);
		if (val1 > val2)
			max = 1;
		else if (val1 < val2)
			max = -1;
		oper1 = oper1->next;
		oper2 = oper2->next;
	}
	if (oper1)
		return (1);
	if (oper2)
		return (-1);
	return (max);
}

t_list		*subtraction(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	t_list	*result;
	int		val2;
	int		val1;
	int		carry;

	carry = 0;
	result = NULL;
	while (oper1)
	{
		val1 = get_val(oper1->content, bistro);
		if (oper2)
			val2 = get_val(oper2->content, bistro);
		else
			val2 = 0;
		if (carry == 1)
		{
			--val1;
			carry = 0;
		}
		if (val2 > val1)
		{
			val1 += bistro->base_size;
			carry = 1;
		}
		val1 -= val2;
		ft_lstappend(&result, ft_lstnew(&(bistro->base[val1]), 1));
		oper1 = oper1->next;
		if (oper2)
			oper2 = oper2->next;
	}
	return (result);
}

void		trim(t_list **result, t_bistro *bistro, int depth)
{
	if ((*result)->next)
		trim(&((*result)->next), bistro, depth + 1);
	if (!((*result)->next) && !get_val((*result)->content, bistro) && depth)
	{
		free(*result);
		*result = NULL;
	}
}

t_list		*subtract(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	int	negative;
	t_list	*result;

	negative = check_size(oper1, oper2, bistro);
	if (negative == -1)
	{
		result = subtraction(bistro, oper2, oper1);
	}
	else
		result = subtraction(bistro, oper1, oper2);
	trim(&result, bistro, 0);
	return (result);

}
