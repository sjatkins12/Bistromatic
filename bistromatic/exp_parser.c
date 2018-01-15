/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:17:36 by satkins           #+#    #+#             */
/*   Updated: 2018/01/08 20:17:39 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

int 	is_opperator(char c, int *flag)
{
	if (c != '(' && c != ')')
		*flag = 1;
	if (c == '(' || c == ')' || c == '*' || c == '-' || c == '+' || c == '/'
		|| c == '%')
		return (1);
	return (0);
}

void	paren_helper(t_bistro *bistro)
{
	char	*top;

	top = ft_stackpop(bistro->operator_stack);
	while (top && *top != '(')
	{
		ft_enqueue(bistro->operand_queue, top, 1);
		free(top);
		top = ft_stackpop(bistro->operator_stack);
	}
	if (!top)
		handle_error(NULL);
	free(top);
}

static void	check_oop(char c, t_bistro *bistro, int *flag)
{
	char	*top;

	if (!is_opperator(c, flag))
		handle_error(NULL);
	top = ft_stackpeak(bistro->operator_stack);
	if (!top || (*top == '(' && c != ')') || c == '(')
		ft_stackpush(bistro->operator_stack, &c, 1);
	else if (c == ')')
		paren_helper(bistro);
	else if ((*top == '-' || *top == '+') && !(c == '+' || c == '-'))
		ft_stackpush(bistro->operator_stack, &c, 1);
	else
	{
		ft_enqueue(bistro->operand_queue, top, 1);
		ft_stackpop(bistro->operator_stack);
		free(top);
		check_oop(c, bistro, flag);
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

void		empty_stack(t_bistro *bistro)
{
	char	*top;

	while (!isempty_stack(bistro->operator_stack))
	{
		top = ft_stackpeak(bistro->operator_stack);
		if (*top == '(')
			handle_error(NULL);
		ft_enqueue(bistro->operand_queue, top, 1);
		ft_stackpop(bistro->operator_stack);
		free(top);
	}
}

void		split_operand(t_bistro *bistro)
{
	int		i;
	t_list	*head;
	int		flag;

	i = 0;
	head = NULL;
	flag = 1;
	while (i < bistro->exp_size && bistro->exp[i])
		if (is_base(bistro->exp[i], bistro))
		{
			while (is_base(bistro->exp[i], bistro))
				ft_lstadd(&head, ft_lstnew(&(bistro->exp[i++]), 1));
			ft_enqueue(bistro->operand_queue, head, sizeof(t_list));
			head = NULL;
			if (!flag)
				handle_error(NULL);
			flag = 0;
		}
		else
			check_oop(bistro->exp[i++], bistro, &flag);
	empty_stack(bistro);
}

int main()
{
	t_bistro	*bistro;
	void		*exp;

	bistro = malloc(sizeof(t_bistro));
	bistro->base = "0123456789";
	bistro->base_size = 10;
	bistro->exp = "5151515115151511151515151551515151+56/5";
	bistro->exp_size = 160;
	bistro->operator_stack = init_stack();
	bistro->operand_queue = init_queue();


	split_operand(bistro);
	while (!isEmpty(bistro->operand_queue))
	{
		exp = ft_dequeue(bistro->operand_queue);
		if (ft_isprint(*(int *)exp))
			ft_putchar(*(char *)exp);
		else
		{
			digitizer(exp);
		}
	}
	printf("\n");
}