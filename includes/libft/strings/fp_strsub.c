#include "libft.h"

void	fp_strsub(char *line, int old, int sub)
{
	size_t	i;

	i = -1;
	while (++i < fp_strlen(line))
	{
		if (line[i] == old)
			line[i] = (char)sub;
	}
}
