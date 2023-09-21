/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:29 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/21 18:19:33 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue.h>
#include <libft.h>

void	enqueue_alloc_onreq(t_queue *front, int bin)
{
	t_queue	*new;

	if (!front)
		new = (t_queue *)fp_calloc(1, sizeof(t_queue));
	else
	{
		new = front;
		while (new->next)
			new = new->next;
		new->next = (t_queue *)fp_calloc(1, sizeof(t_queue));
		new = new->next;
		new->bin = bin;
	}
}

void	enqueue_pre_alloc(t_queue *front, int bin)
{
	t_queue	*new;
	t_queue	*temp;

	new = (t_queue *)fp_calloc(1, sizeof(t_queue));
	new->bin = bin;
	if (!front)
	{
		front = new;
		return ;
	}
	temp = front;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}
