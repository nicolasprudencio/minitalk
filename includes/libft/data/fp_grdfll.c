#include "libft.h"

void	fp_grdfll(char **grid, char fill, int width, int height)
{
	int	area;
	int	i;
	int	x;
	int	y;

	if (!grid || !fill)
		return ;
	area = width * height;
	i = -1;
	while (++i < area)
	{
		y = i / width;
		x = i % width;
		grid[y][x] = fill;
	}
}
