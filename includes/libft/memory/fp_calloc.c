/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:42:43 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/21 18:55:50 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fp_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	int		over;

	over = nmemb * size;
	if (over != 0 && over / size != nmemb)
		return (NULL);
	ret = (void *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	fp_memset(ret, 0, (nmemb * size));
	return (ret);
}
