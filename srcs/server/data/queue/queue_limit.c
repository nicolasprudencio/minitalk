/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_limit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:43:23 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 18:43:27 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

char	dequeue_limit(t_queue **front, int minimum)
{
	int	i;

	if ((int)queue_len(front) < minimum)
		return (-1);
	i = -1;
	return (dequeue_btoc(front));
}
