/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:23:48 by satkins           #+#    #+#             */
/*   Updated: 2018/01/10 16:23:50 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

static int		get_val(char *c, t_bistro *bistro)
{
	int	i;

	i = -1;
	while (++i < bistro->base_size)
		if (*c == bistro->base[i])
			return (i);
	return (-1);
}

t_list	*addition(t_bistro *bistro, t_list *operand1, t_list *operand2)
{
	int		carry;
	int		val[3];
	t_list	*result;

	carry = 0;
	result = NULL;
	while (operand1 || operand2 || carry)
	{
		val[0] = (operand1 ? get_val(operand1->content, bistro) : 0);
		val[1] = (operand2 ? get_val(operand2->content, bistro) : 0);
		val[2] = val[0] + val[1] + carry;
		carry = val[2] / bistro->base_size;
		val[2] = val[2] % bistro->base_size;
		ft_lstappend(&result, ft_lstnew(&(bistro->base[val[2]]), 1));
		operand1 = operand1 ? operand1->next : NULL;
		operand2 = operand2 ? operand2->next : NULL;
	}
	return (result);
}

// int	main()
// {
// 	t_list	*op1;
// 	t_list	*op2;
// 	t_list	*result;
// 	t_bistro	*bistro;
// 	char *str = "CBB";
// 	char *str1 = "IBI";

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

// 	bistro = malloc(sizeof(t_bistro));
// 	bistro->base = "ABCDEFGEHI";
// 	bistro->base_size = 10;

// 	result = addition(bistro, op1, op2);
// 	while (result)
// 	{
// 		printf("%s", (char *)result->content);
// 		result = result->next;
// 	}
// 	printf("\n");

// }