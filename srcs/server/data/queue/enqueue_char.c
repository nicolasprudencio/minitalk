#include "queue.h"

int	enqueue_char(char c, t_queue **front)
{
	char	*bin;
	int		i;

	if (!c)
	{
		fp_printf("Error: char is undefined!");
		return (0);
	}
	else if (!front)
	{
		fp_printf("Error: queue is undefined!");
		return (0);
	}
	bin = char_to_bin(c);
	i = -1;
	while (bin[++i])
	{
		if (bin[i] == '1')
			enqueue_alloc_onreq(front, 1);
		else
			enqueue_alloc_onreq(front, 0);
	}
	free(bin);
	bin = NULL;
	return (1);
} 