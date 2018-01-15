/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_expression.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:02:15 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/15 01:23:39 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

void	stoi(char *str) //string to integer
{
	int i;
	double res;

	i = -1;
	while (str[i++] != '\0')
		res = res * 10 + ft_atoi(str[i]); //converts ASCII characters to integers (maybe we dont need this)
	return (res);
}

t_list		infix_to_rpn(char *str, t_bistro *bistro) //test logic
{
	char		*top;
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		top = ft_stackpop(bistro->operator_stack);
		if (!(check_operator(str[i])))
			top = top + str[i];
		else if (check_operator(str[i]))
		{
			while (check_operator(precedence(str[i]), top) && top == NULL) //the top has higher precedence and is not empty
			top =
		}
		// 	push str[i] to the stack
		// else if there is a '('
		//	pop stack
		// else if there is a ')'
		//	pop stack
	}
	return (str);
}

bool	check_operator(char oper, t_bistro *bistro)
{
	char	*top;

	top = ft_stackpeak(bistro->operator_stack);
	if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '%')
		return (true);
	return (false);
}

int		precedence(char oper)
{
	if (oper == '*' || oper == '/' || oper == '%') //higher
		return (1);
	if (oper == '+' || oper == '-') //lower
		return (2);
}

void	operator_cases(char oper, int a, int b)
{
	if (oper == '/' && b != 0)
		return (a/b);
	if (oper == '*')
		return (a*b);
	if (oper == '%')
		return (a%b);
	if (oper == '+')
		return (a+b);
	if (oper == '-')
		return (a-b);
}
