#include "libft.h"

int	fp_grdlen(char **grid)
{
	int	i;

	if (!grid)
		return (0);
	i = 0;
	while (grid[i])
		i++;
	return (i);
}
