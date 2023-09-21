#include "queue.h"
#include "libft.h"

int	dequeue_fauna(t_queue *front)
{
	int		bin;
	t_queue	*temp;

	if (!front)
		return (-1);
	bin = front->bin;
	if (!front->next)
	{
		free(front);
		front = NULL;
		return (bin);
	}
	temp = front;
	front = front->next;
	free(temp);
	temp = NULL;
	return (bin);
}

int	dequeue_nikko(t_queue *front)
{
	t_queue	*aux;
	int		bin;

	if (!front)
		return (-1);
	bin = front->bin;
	aux = front;
	if (front->next)
		front = front->next;
	else
	{
		free(front);
		front = NULL;
		return (bin);
	}
	free(aux);
	aux = NULL;
	return (bin);
}
