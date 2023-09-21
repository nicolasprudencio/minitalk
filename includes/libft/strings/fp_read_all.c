#include "libft.h"

char	*fp_read_all(int fd)
{
	char	*line;
	char	*output;

	output = fp_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		output = fp_strjoin(output, line, 2);
	}
	return (output);
}
