/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 01:11:16 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/12 17:36:25 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "bistro.h"
/*TODO: Must be tested properly for all datatypes.
		Maybe make this as a header?
		Remove main before submitting
		Rigorous test cases
*/

t_queue				*init_queue(void)
{
	t_queue			*node;
	node = (t_queue *)malloc(sizeof(t_queue));
	node->first = NULL;
	node->last = NULL;
	return (node);
}

void				ft_enqueue(t_queue *queue, void *content, size_t c_size)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = ft_memalloc(c_size);
	node->content = ft_memmove(node->content, content, c_size);
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

// int		main(void)
// {
// 	t_queue *node;

// 	node = init_queue();
// 	enqueue(node, "6 + 6");
// 	printf("\nfirst is: %s", peek_queue(node));
// 	printf("\ncurrent queue: %d",isEmpty(node));
// 	printf("\ndequeued first: %s",dequeue(node));
// 	printf("\ncurrent queue: %d",isEmpty(node));
// 	return (0);
// }
