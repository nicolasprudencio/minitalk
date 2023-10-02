/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:55:18 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:55:45 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue.h>
#include <libft.h>

int	enqueue(t_queue **front, int bin)
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
