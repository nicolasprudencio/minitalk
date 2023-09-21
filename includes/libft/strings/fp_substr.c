/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:58:06 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/23 11:05:15 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (NULL);
	if (start > fp_strlen(s))
		return (fp_strdup(""));
	if (fp_strlen(s) - start >= len)
		subs = (char *)malloc(sizeof(char) * (len + 1));
	else
		subs = (char *)malloc(sizeof(char) * ((fp_strlen(s) - start) + 1));
	if (!subs)
		return (NULL);
	fp_strlcpy(subs, (s + start), (len + 1));
	return (subs);
}
