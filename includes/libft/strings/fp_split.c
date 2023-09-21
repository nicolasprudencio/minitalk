/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:41:01 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 10:17:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**fp_split(const char *str, int c)
{
	char	**output;
	char		*p;
	int			grid_size;
	int			i;

	if (!str)
		return (NULL);
	grid_size = fp_chrcnt(str, c) + 1;
	if (str[0] == c)
		grid_size--;
	if (str[fp_strlen(str)] == c)
		grid_size--;
	output = (char **)fp_calloc(grid_size + 1, sizeof(char *));
	if (!output)
		return (NULL);
	p = (char *)str;
	i = -1;
	while (++i < grid_size)
	{
		while (p && *p == c)
			p++;
		output[i] = fp_strcpyto(p, c);
		p = fp_strchr(p, c);
	}
	return (output);
}
