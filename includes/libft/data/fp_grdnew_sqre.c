#include "libft.h"

char	**fp_grdnew_sqre(int size)
{
	char	**grid;
	int			i;

	if (size <= 0)
		return (NULL);
	i = -1;
	grid = (char **)fp_calloc(size + 1, sizeof(char *));
	while (++i < size)
	{
		grid[i] = (char *)fp_calloc(size + 1, sizeof(char));
	}
	return (grid);
}
