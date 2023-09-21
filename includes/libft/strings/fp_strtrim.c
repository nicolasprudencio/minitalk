/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:32:21 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/14 05:39:54 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_strtrim(char const *s1, char const *set)
{
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (fp_strchr(set, *s1) && *s1 != '\0')
		s1++;
	size = fp_strlen((char *)s1);
	while (fp_strchr(set, s1[size]) && size != 0)
		size--;
	return (fp_substr((char *)s1, 0, size +1));
}
