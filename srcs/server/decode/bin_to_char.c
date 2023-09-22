/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:03 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/22 17:13:35 by nprudenc         ###   ########.fr       */
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
	n = 7;
	output = '\0';
	bin = dequeue_fauna(front);
	while (n >= 0)
	{ 	
		output |= (bin << n--);
		bin = dequeue_fauna(front);
			 
	}
	return (output);
}
