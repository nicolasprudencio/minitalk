/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:03 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 14:10:32 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "libft.h"
#include <stdio.h>

char	bin_to_char(t_queue **front)
{
	char	output;
	int		bin;
	int		n;

	if (!*front)
		return (-1);
	if (queue_len(front) < 8)
	{	
		fp_printf("Error: Queue doesn't have enough bits for a char character\n");
		return (-1);
	}
	n = 7;
	output = '\0';
	while (n >= 0)
	{ 	
		bin = dequeue_nikko(front);
		output |= (bin << n--);
	}
	return (output);
}
