/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:28 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 16:27:03 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <libft.h>
# include <signal.h>


typedef struct s_queue {
	struct s_queue	*next;
	int				bin;
}				t_queue;

char		dequeue_limit(t_queue **front, int minimum);
int		dequeue(t_queue **front);
int		dequeue_nikko(t_queue **front);
int		dequeue_fauna(t_queue **front);
int		enqueue_pre_alloc(t_queue **front, int bin);
int		enqueue_alloc_onreq(t_queue **front, int bin);
int		enqueue_char(char c, t_queue **front);
char	dequeue_btoc(t_queue **front);
size_t	queue_len(t_queue **front);

char	*char_to_bin(char input);

#endif
