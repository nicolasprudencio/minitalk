/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:18:00 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/22 17:31:22 by nprudenc         ###   ########.fr       */
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