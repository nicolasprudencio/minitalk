/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_limit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:56:01 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:56:02 by fpolaris         ###   ########.fr       */
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
