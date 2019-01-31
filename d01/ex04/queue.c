/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:38:08 by ytran             #+#    #+#             */
/*   Updated: 2019/01/09 19:38:20 by ytran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_queue *queueInit(void)
{
    t_queue *queue = (t_queue*)malloc(sizeof(t_queue));

    if (!queue)
        return (NULL);
    queue->first = NULL;
    queue->last = NULL;
    return (queue);
}

char *dequeue(struct s_queue *queue)
{
    struct s_node	*node;
	void			*message;

	if (isEmpty(queue))
		return (NULL);
	node = queue->first;
	message = queue->first->message;
	queue->first = queue->first->next;
	free(node);
	return(message);
}

void enqueue(struct s_queue *queue, char *message)
{
    struct s_node	*node;

	node = malloc(sizeof(struct s_node));
	if (!node)
		return ;
	node->message = message;
	node->next = NULL;
	if (isEmpty(queue))
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;

}

char *peek(struct s_queue *queue)
{
    return ((isEmpty(queue) == 1) ? NULL : queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
    return ((queue->first == NULL) ? 1 : 0);
}
