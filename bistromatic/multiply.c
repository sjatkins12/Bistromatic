/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:13:28 by satkins           #+#    #+#             */
/*   Updated: 2018/01/13 19:27:13 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

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

t_list	*decrement(t_bistro *bistro, t_list *oper)
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

t_list	*multiplier(t_bistro *bistro, t_list *oper1, t_list *oper2)
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

t_list *multiply(t_bistro *bistro, t_list *oper1, t_list *oper2)
{
	int	size;

	size = check_size(oper1, oper2, bistro);
	if (size == -1)
		return (multiplier(bistro, oper2, oper1));
	else
		return (multiplier(bistro, oper1, oper2));
}

// 
// int	main()
// {
// 	t_list	*op1;
// 	t_list	*op2;
// 	t_list	*result;
// 	t_bistro	*bistro;
// 	char *str = "24871444";
// 	char *str1 = "44";
//
// 	op1 = NULL;
// 	op2 = NULL;
// 	while (*str)
// 	{
// 		ft_lstadd(&op1, ft_lstnew(str, 1));
// 		str++;
// 	}
// 	while (*str1)
// 	{
// 		ft_lstadd(&op2, ft_lstnew(str1, 1));
// 		str1++;
// 	}
//
// 	bistro = malloc(sizeof(t_bistro));
// 	bistro->base = "0123456789";
// 	bistro->base_size = 10;
//
// 	result = multiply(bistro, op1, op2);
// 	digitizer(result);
// 	printf("\n");
// }