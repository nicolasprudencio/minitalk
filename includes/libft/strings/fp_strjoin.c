/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:12:49 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 16:36:47 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_strjoin(char const *s1, char const *s2, int flag)
{
	char	*newstr;

	newstr = (char *)malloc((fp_strlen(s1)
			+ fp_strlen(s2)) + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	fp_memcpy((void *)newstr, s1, fp_strlen(s1) + 1);
	fp_memcpy((void *)&newstr[fp_strlen(s1)], s2, fp_strlen(s2) + 1);
	if (flag > 0)
		free((char *)s1);
	if (flag > 1)
		free((char *)s2);
	return (newstr);
}
