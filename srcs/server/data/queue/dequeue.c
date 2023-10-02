/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:55:13 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:57:59 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "libft.h"

int	dequeue(t_queue **front)
{
	int		bin;
	t_queue	*temp;

	if (!*front)
		return (-1);
	temp = *front;
	bin = temp->bin;
	if (!temp->next)
	{
		free(*front);
		*front = NULL;
		return (bin);
	}
	*front = temp->next;
	free(temp);
	temp = NULL;
	return (bin);
}
