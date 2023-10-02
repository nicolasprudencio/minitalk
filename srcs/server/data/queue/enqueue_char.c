/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:55:24 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:55:25 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	enqueue_char(char c, t_queue **front)
{
	char	*bin;
	int		i;

	if (!c)
	{
		fp_printf("Error: char is undefined!");
		return (0);
	}
	else if (!front)
	{
		fp_printf("Error: queue is undefined!");
		return (0);
	}
	bin = char_to_bin(c);
	i = -1;
	while (bin[++i])
	{
		if (bin[i] == '1')
			enqueue(front, 1);
		else
			enqueue(front, 0);
	}
	free(bin);
	bin = NULL;
	return (1);
}
