/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 01:11:16 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/10 02:27:23 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//TODO: Must be tested properly for all datatypes.
//Source: https://www.geeksforgeeks.org/queue-set-2-linked-list-implementation/

typedef struct		s_node
{
	void			*content;
	struct s_node 	*next;
}					t_node;

typedef struct		s_queue //Is the size of the queue needed?
{
	struct s_node	*first;
	struct s_node 	*last;
}					t_queue;

t_queue *create_node(void *value) //pulled from btree (maybe change "void" to "int"?)
{
	t_node *root;

	root = (t_node *)malloc(sizeof(t_node));
	root->content = value;
	root->next = NULL;
	return (root);
}

t_queue		*create_queue(void)
{
	t_queue *start;

	start = (t_queue *)malloc(sizeof(t_queue));
	start->first = NULL;
	start->last = NULL;
	return (start);
}

void enqueue(t_queue *queue, void *content)
{
	t_queue *node;

	node = create_node(content);
	if (queue->last == NULL)
	{
		queue->last = node;
		queue->first = queue->last;
		return ;
	}
	queue->last->next = node;
	queue->last = node;
}

void *dequeue(t_queue *queue)
{
	t_queue *node;

	node = queue->first;
	if (queue->first == NULL)
		return (NULL);
	queue->first = queue->first->next;
	if (queue->first == queue->last)
		queue->last = NULL;
	free(node);
}
