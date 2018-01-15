/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:00:16 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/14 15:21:19 by ztisnes          ###   ########.fr       */
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

t_list		*modulo(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	t_list	*tmp;

	while (check_size(oper1, oper2, bistro) == 1)
	{
		tmp = oper1;
		oper1 = subtract(bistro, oper1, oper2);
		del_num(tmp);
	}
	return (oper1);
}
