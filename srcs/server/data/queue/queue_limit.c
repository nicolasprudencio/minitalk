#include "queue.h"

char	dequeue_limit(t_queue **front, int minimum)
{
	int	i;

	if ((int)queue_len(front) < minimum)
		return (-1);
	i = -1;
	return (dequeue_btoc(front));
}
