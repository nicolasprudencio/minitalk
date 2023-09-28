#include "queue.h"

char	dequeue_limit(t_queue **front, int minimum)
{
	int	q_len;
	int	i;

	q_len = queue_len(front);
	if (q_len < minimum)
		return (-1);
	i = -1;
	return (dequeue_btoc(front));
}
