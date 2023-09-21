/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:01:56 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/19 13:02:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != (char)c) && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
