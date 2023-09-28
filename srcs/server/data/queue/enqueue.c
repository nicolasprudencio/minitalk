/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:29 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 18:43:40 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue.h>
#include <libft.h>

int	enqueue_alloc_onreq(t_queue **front, int bin)
{
	t_queue	*new;

	if (!*front)
	{
		*front = (t_queue *)fp_calloc(1, sizeof(t_queue));
		return (1);
	}
	else if (!*front)
		return (0);
	else
	{
		new = *front;
		while (new->next)
			new = new->next;
		new->next = (t_queue *)fp_calloc(1, sizeof(t_queue));
		if (!new->next)
			return (0);
		new = new->next;
		new->bin = bin;
	}
	return (1);
}

int	enqueue_pre_alloc(t_queue **front, int bin)
{
	t_queue	*new;
	t_queue	*temp;

	new = (t_queue *)fp_calloc(1, sizeof(t_queue));
	if (!new)
		return (0);
	new->bin = bin;
	if (!*front)
	{
		*front = new;
		return (1);
	}
	temp = *front;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (1);
}
