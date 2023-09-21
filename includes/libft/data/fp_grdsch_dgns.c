#include "libft.h"

int	fp_grdsch_dgns(char **grid, int y, int x, char target)
{
	int	output;

	output = 0;
	if (grid[y - 1][x + 1] == target)
		output++;
	if (grid[y + 1][x - 1] == target)
		output++;
	if (grid[y + 1][x + 1] == target)
		output++;
	if (grid[y - 1][x - 1] == target)
		output++;
	return (output);
}
