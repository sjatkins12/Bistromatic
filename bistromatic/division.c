/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:11:10 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/13 21:42:58 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

/*
** Pseudocode of division by substraction:
** 		Counter from 0
** 		While N >= D
** 			N := N-D
** 			Counter++
** 		return counter
*/

void	del_num(t_list *oper)
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

t_list	*increment(t_bistro *bistro, t_list *oper)
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
	/*
		TODO:	Take care of the remainder
				Subtraction must be used with the function made
				Anything else?
	*/
	t_list	*result;
	t_list	*tmp;

	result = NULL;
	ft_lstadd(&result, ft_lstnew(&(bistro->base[0]), 1));
	printf("\ntest");
	while (oper2->content >= oper1->content)
	{
		tmp = result;
		result = subtract(bistro, result, oper1);
		del_num(tmp);
		oper2 = increment(bistro, oper2);
	}
	printf("\ntest2");
	return (result);
}

t_list *divide(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	int	size;

	size = check_size(oper2, oper1, bistro);
	if (size == -1)
		return (division(bistro, oper1, oper2));
	else
		return (division(bistro, oper2, oper1));
}

int	main()
{
	t_list	*op1;
	t_list	*op2;
	t_list	*result;
	t_bistro	*bistro;
	char *str = "6";
	char *str1 = "2";

	op1 = NULL;
	op2 = NULL;
	while (*str)
	{
		ft_lstadd(&op1, ft_lstnew(str, 1));
		str++;
	}
	while (*str1)
	{
		ft_lstadd(&op2, ft_lstnew(str1, 1));
		str1++;
	}

	bistro = malloc(sizeof(t_bistro));
	bistro->base = "0123456789";
	bistro->base_size = 10;

	result = divide(bistro, op1, op2);
	digitizer(result);
	printf("\n");
}
