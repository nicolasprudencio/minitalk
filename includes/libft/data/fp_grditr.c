#include "libft.h"

int	fp_grditr(char **grid, int op, void (*fp) (char *, int))
{
	int	output;
	int	i;
	int	higher_nbr;

	if (!grid)
		return (0);
	i = -1;
	output = 0;
	while (grid[++i])
	{
		fp(grid[i], op);
		higher_nbr = fp_atoi(grid[i]);
		if (higher_nbr > output)
			output = higher_nbr;
	}
	return (output);
}
