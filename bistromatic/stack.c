/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:57:20 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/12 15:12:47 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//TODO: Must be tested properly for all datatypes. Remove main before submitting
//		Remove "#includes" once fixes are made.
//		Add structs to bistro.h

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack
{
	t_node		*top;
}				t_stack;

t_stack				*init_stack(void)
{
	t_stack			*node;
	node = (t_stack *)malloc(sizeof(t_stack));
	node->top = NULL;
	return (node);
}

void				push_stack(t_stack *stack, void *content)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void				*pop_stack(t_stack *stack)
{
	t_node			*next;
	void			*anything;

	if (stack->top == NULL)
		return (NULL);
	next = stack->top->next;
	anything = stack->top->content;
	free(stack->top);
	stack->top = next;
	return (anything);
}

void				*peek(t_stack *stack)
{
	if (stack->top == NULL)
		return (NULL);
	return (stack->top->content);
}

int					isEmpty_stack(t_stack *stack)
{
	return (stack->top == NULL);
}

int main(void)
{
	t_stack *node = init_stack();
	push_stack(node, "123456");
	printf("\ncurrent top: %s",peek_stack(node));
	printf("\ncurrent top: %s",pop_stack(node));
	printf("\ncurrent top: %s",peek_stack(node));
	return (0);
}
