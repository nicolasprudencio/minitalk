#include "queue.h"

char	*char_to_bin(char input)
{
	char	*output = (char *)fp_calloc(9, sizeof(char));
	char	current;
	char	mask;
	int		bit;
	
	bit = 8;
	mask = 1;
	while (bit > 0)
	{
		current = (input >> --bit) & mask;
		if (current == 1)
			output[-bit + 7] = '1';
		else
			output[-bit + 7] = '0';
	}
	return (output);
}