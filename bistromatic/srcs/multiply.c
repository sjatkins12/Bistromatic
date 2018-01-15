/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:13:28 by satkins           #+#    #+#             */
/*   Updated: 2018/01/14 15:29:50 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

void		del_num(t_list *oper)
{
	t_list	*next;

	while (oper)
	{
		next = oper;
		free(next->content);
		oper = oper->next;
		free(next);
	}
}

t_list		*decrement(t_bistro *bistro, t_list *oper)
{
	t_list	*dec;
	t_list	*result;

	dec = NULL;
	ft_lstadd(&dec, ft_lstnew(&(bistro->base[1]), 1));
	result = subtract(bistro, oper, dec);
	del_num(oper);
	free(dec->content);
	free(dec);
	return (result);
}

t_list		*multiplier(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	t_list	*result;
	t_list	*tmp;

	result = NULL;
	ft_lstadd(&result, ft_lstnew(&(bistro->base[0]), 1));
	while (oper2->next || *(char *)(oper2->content) != bistro->base[0])
	{
		tmp = result;
		result = addition(bistro, result, oper1);
		del_num(tmp);
		oper2 = decrement(bistro, oper2);
	}
	return (result);
}

t_list		*multiply(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	int		size;

	size = check_size(oper1, oper2, bistro);
	if (size == -1)
		return (multiplier(bistro, oper2, oper1));
	else
		return (multiplier(bistro, oper1, oper2));
}
