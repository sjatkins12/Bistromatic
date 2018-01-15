/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 01:11:16 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/14 15:15:58 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

/* TODO:Must be tested properly for all datatypes.
**		Maybe make this as a header?
**		Remove main before submitting
**		Rigorous test cases
**		queue->first = tmp->next; //Possible seg failt because
**		I'm dereferencing first without checking if is NULL. Fix for this is
**		having it inside of the tmp if condition.
*/

t_queue				*init_queue(void)
{
	t_queue			*node;
	node = (t_queue *)malloc(sizeof(t_queue));
	node->first = NULL;
	node->last = NULL;
	return (node);
}

void				ft_enqueue(t_queue *queue, void *content)
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

void				*ft_dequeue(t_queue *queue)
{
	t_node			*tmp;

	tmp = queue->first;
	if (tmp)
	{
		queue->first = tmp->next;
		return (tmp->content);
	}
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
