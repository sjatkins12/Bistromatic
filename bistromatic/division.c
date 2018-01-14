/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:11:10 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/14 15:20:58 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

/*
** Pseudocode of division by substraction:
** 		Counter from 0
** 		While N >= D
** 			N := N-D
** 			(Counter for D)
**			(again, subtract with D)
**			(if numerator and denominator = 0, continue to the next index)
** 		return result
*/

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

t_list		*increment(t_bistro *bistro, t_list *oper)
{
	t_list	*incr;
	t_list	*counter;

	incr = NULL;
	ft_lstadd(&incr, ft_lstnew(&(bistro->base[1]), 1));
	counter = addition(bistro, oper, incr);
	del_num(oper);
	free(incr->content);
	free(incr);
	return (counter);
}

t_list		*division(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	t_list	*result;
	t_list	*tmp;

	result = NULL;
	ft_lstadd(&result, ft_lstnew(&(bistro->base[0]), 1));
	while (check_size(oper1, oper2, bistro) == 1)
	{
		tmp = oper1;
		oper1 = subtract(bistro, oper1, oper2);
		del_num(tmp);
		result = increment(bistro, result);
	}
	return (result);
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
