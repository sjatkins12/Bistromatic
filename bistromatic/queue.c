/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 01:11:16 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/12 15:18:18 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
/*TODO: Must be tested properly for all datatypes.
		Maybe make this as a header?
		Remove main before submitting
		Rigorous test cases
*/

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue
{
	t_node			*first;
	t_node		 	*last;
}					t_queue;

t_queue				*init_queue(void)
{
	t_queue			*node;
	node = (t_queue *)malloc(sizeof(t_queue));
	node->first = NULL;
	node->last = NULL;
	return (node);
}

void				enqueue(t_queue *queue, void *content)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	if (!queue->last)
	{
		queue->last = node;
		queue->first = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = queue->last->next;
	}
	return ;
}

void				*dequeue(t_queue *queue)
{
	t_node			*tmp;

	tmp = queue->first;
	queue->first = tmp->next;
	if (tmp)
		return (tmp->content);
	return (NULL);
}

void 				*peek_queue(t_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int					isEmpty(t_queue *queue)
{
	return (queue->first == NULL);
}

int		main(void)
{
	t_queue *node;

	node = init_queue();
	enqueue(node, "6 + 6");
	printf("\nfirst is: %s", peek_queue(node));
	printf("\ncurrent queue: %d",isEmpty(node));
	printf("\ndequeued first: %s",dequeue(node));
	printf("\ncurrent queue: %d",isEmpty(node));
	return (0);
}
