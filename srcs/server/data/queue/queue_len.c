/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:55:55 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:55:56 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue.h>

size_t	queue_len(t_queue **front)
{
	t_queue	*temp;
	size_t	counter;

	if (!*front)
		return (0);
	counter = 0;
	temp = (t_queue *)front;
	while (temp->next)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
