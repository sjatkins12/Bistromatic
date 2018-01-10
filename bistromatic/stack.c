/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:57:20 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/10 02:26:57 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//TODO: Must be tested properly for all datatypes

//1st try
// typedef struct		s_stack
// {
// 	double			value;
// 	struct s_stack	*next;
// }					t_stack;
//
// /*
// ** Functions by type stack.h
// */
//
// void				ft_stck_push(t_stack *top, double newdata);
// double				ft_stck_pop(t_stack *top);
//
// double	ft_stck_pop(t_stack *top)
// {
// 	double	value;
// 	t_stack	*tmp;
//
// 	if (top)
// 	{
// 		tmp = top->next;
// 		if (tmp != NULL)
// 		{
// 			value = tmp->value;
// 			top->next = tmp->next;
// 			free(tmp);
// 			return (value);
// 		}
// 	}
// 	return (top->value);
// }


// 2nd try...
typedef struct		s_node
{
	void			*content; //Check datatype
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*top; //t_node?
}					t_stack;

t_stack *stack_create(void)
{
	t_stack *top;

	top = (t_stack *)malloc(sizeof(t_stack));
	if (top)
	{
		top->head = NULL;
		top->max_size = 0;
	}
	return (top);
}

char	stack_peek(t_stack *stack)
{
	// return (stack->head->content) ? (stack && stack->head) : NULL;
	return (*(stack->head->content));
}

void	*stack_push(t_stack *top, char *data)
{
	t_stack *node;

	if (top)
	{
		if (!(node == malloc(sizeof(t_stack))))
			return (NULL);
		node->content = data;
		node->next = top->head;
		top->head = node;
		top->max_size++;
	}
	return (node);
}

void	stack_pop(t_stack *top)
{
	t_stack *tmp;

	if (top->head != NULL)
	{
		tmp = top->head;
		top->head = top->head->next;
		free(tmp->content);
		free(tmp);
		top->max_size--;
	}
}

int		main(void)
{
	t_stack *stack;
	stack = stack_create();
	char *data;
	stack_push(stack, "test");
}


typedef struct		s_node
{
	void 			*data;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*top;
}					t_stack;

t_stack *stack_create(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack)
	{
		stack->top = NULL;

	}
}

//3rd possible way?
// typedef struct		s_stack
// {
// 	int				*data;
// 	size_t			size;
// 	int				top;
// }					t_stack;
//
// t_stack		*create_stack(size_t size)
// {
// 	t_stack *stack;
// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	stack->size = size;
// 	stack->top = -1;
// 	stack->data = (void *)malloc(stack->size * sizeof(void *));
// 	return (stack);
// }
//
// int		full_stack(t_stack *stack)
// {
// 	return (stack->top == stack->size - 1);
// }
//
// void	push_stack(t_stack *stack, void *item)
// {
// 	if (full_stack(stack))
// 		return ;
// 	stack->data[++stack->top] = item;
// 	printf("%d pushed\n", item);
// }
//
// int		pop_stack(t_stack *stack)
// {
// 	return (stack->data[stack->top--]);
// }
// int main(void)
// {
// 	t_stack *test = create_stack(100);
// 	push_stack(test,5);
// 	printf("%d popped from stack\n", pop_stack(test));
// 	return (0);
// }
