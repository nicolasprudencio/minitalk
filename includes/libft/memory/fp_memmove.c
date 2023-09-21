/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:55:11 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/23 10:35:21 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fp_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (d == s)
		return (dest);
	if (d < s)
	{
		while (n-- > 0)
			*d++ = *s++;
		return (dest);
	}
	d += n - 1;
	s += n - 1;
	while (n-- > 0)
		*d-- = *s--;
	return (dest);
}
