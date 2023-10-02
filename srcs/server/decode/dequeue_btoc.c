/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_btoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:56:21 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:56:22 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

char	dequeue_btoc(t_queue **front)
{
	char	output;
	int		bin;
	int		n;

	if (!*front)
		return (-1);
	if (queue_len(front) < 8)
	{	
		fp_printf("Error: Not enough bits for dequeue\n");
		return (-1);
	}
	n = 7;
	output = '\0';
	while (n >= 0)
	{
		bin = dequeue(front);
		if (bin == -1)
			return (-1);
		output |= (bin << n--);
	}
	return (output);
}
