/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:03 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 20:04:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

char	dequeue_bin(t_queue **front)
{
	char	output;
	int		bin;
	int		n;

	if (!*front)
		return (-1);
	if (queue_len(front) < 8)
	{	
		fp_printf("Error:");
		fp_printf("Not enough bits for dequeue\n");
		return (-1);
	}
	n = 7;
	output = '\0';
	while (n >= 0)
	{ 	
		bin = dequeue(front);
		output |= (bin << n--);
	}
	return (output);
}
