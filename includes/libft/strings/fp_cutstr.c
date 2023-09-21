/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_cutstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:49 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/21 11:09:43 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_cutstr(char const *s, unsigned int start, size_t len)
{
	size_t	end;
	size_t	count;
	char	*output;

	end = 0;
	count = 0;
	while (s[end] != '\0')
		end++;
	if (start >= end)
		start = end;
	if (len > end - start)
		len = end - start;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	while (count < len)
	{
		output[count] = s[start + count];
		count++;
	}
	output[count] = '\0';
	free((void *)s);
	return (output);
}
