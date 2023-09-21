/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:01:33 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/20 18:14:51 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_strrchr(const char *s, int c)
{
	size_t			end;
	unsigned char	target;

	target = (unsigned char)c;
	if (target == '\0')
		return ((char *)&s[fp_strlen(s)]);
	end = fp_strlen(s);
	while (end > 0)
	{
		if (s[end - 1] == target)
			return ((char *)&s[end - 1]);
		end--;
	}
	return (NULL);
}
