/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:54:37 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:54:39 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

char	*char_to_bin(char input)
{
	char	*output;
	char	current;
	char	mask;
	int		bit;

	bit = 8;
	mask = 1;
	output = (char *)fp_calloc(9, sizeof(char));
	if (!output)
		return (NULL);
	if (!input)
	{
		fp_printf("Error: input char is undefined!");
		return (NULL);
	}
	while (bit > 0)
	{
		current = (input >> --bit) & mask;
		if (current == 1)
			output[-bit + 7] = '1';
		else
			output[-bit + 7] = '0';
	}
	return (output);
}
