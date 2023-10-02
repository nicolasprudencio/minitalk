/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:57:22 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:57:39 by fpolaris         ###   ########.fr       */
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
int		enqueue(t_queue **front, int bin);
int		enqueue_char(char c, t_queue **front);
char	dequeue_btoc(t_queue **front);
size_t	queue_len(t_queue **front);

char	*char_to_bin(char input);

#endif
