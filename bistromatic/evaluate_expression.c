/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_expression.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:02:15 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/09 18:48:54 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"
#include <stdio.h>
#include <stdlib.h>

/*void	stoi(char *str) //string to integer
{
	int i;
	double res;

	i = -1;
	while (str[i++] != '\0')
		res = res * 10 + ft_atoi(str[i]); //converts ASCII characters to integers (maybe we dont need this)
	return (res);
}
*/


//FIXME: Move it to seperate functions
bool	check_operator(char oper)
{
	if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
		return (true);
	return false;
}

int		precedence(char oper)
{
	if (oper == '*' || oper == '/' || oper == '%')
		return (1);
	if (oper == '+' || oper == '-')
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
