#include "libft.h"

char	**fp_grdnew(int width, int height)
{
	char	**grid;
	int			i;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = (char **)fp_calloc(height + 1, sizeof(char *));
	i = -1;
	while (++i < width)
	{
		grid[i] = (char *)fp_calloc(width + 1, sizeof(char));
	}
	return (grid);
}
