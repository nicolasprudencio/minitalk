#include "queue.h"
#include "libft.h"

int	dequeue_fauna(t_queue **front)
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

int	dequeue_nikko(t_queue **front)
{
	t_queue	*aux;
	int		bin;

	if (!*front)
		return (-1);
	aux = *front;
	bin = aux->bin;
	if (aux->next)
		*front = aux->next;
	else
	{
		free(*front);
		*front = NULL;
		return (bin);
	}
	free(aux);
	aux = NULL;
	return (bin);
}
