#include "libft.h"

double	fp_dlerp(int x, int y, double t)
{
	return ((1 - t) * x + (t * y));
}

int	fp_ilerp(int x, int y, double t)
{
	return ((1 - t) * x + (t * y));
}

float	fp_flerp(int x, int y, float t)
{
	return ((1 - t) * x + (t * y));
}

double	fp_lerpcolor(int cx, int cy, double t)
{
	int	red[3];
	int	green[3];
	int	blue[3];

	red[0] = (cx >> 16) & 0xFF;
	green[0] = (cx >> 8) & 0xFF;
	blue[0] = cx & 0xFF;
	red[1] = (cy >> 16) & 0xFF;
	green[1] = (cy >> 8) & 0xFF;
	blue[1] = cy & 0xFF;
	red[2] = fp_ilerp(red[0], red[1], t);
	green[2] = fp_ilerp(green[0], green[1], t);
	blue[2] = fp_ilerp(blue[0], blue[1], t);
	return ((red[2] << 16) | (green[2] << 8) | blue[2]);
}
