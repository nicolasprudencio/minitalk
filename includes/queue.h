/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:28 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 20:09:15 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <libft.h>

typedef struct s_queue {
	struct s_queue	*next;
	int				bin;
}				t_queue;

int		dequeue(t_queue **front);
int		dequeue_nikko(t_queue **front);
int		dequeue_fauna(t_queue **front);
char	dequeue_bin(t_queue **front);
void	enqueue_pre_alloc(t_queue **front, int bin);
void	enqueue_alloc_onreq(t_queue **front, int bin);
size_t	queue_len(t_queue **front);

char	*char_to_bin(char input);

#endif
