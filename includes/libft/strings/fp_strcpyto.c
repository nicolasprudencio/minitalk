#include "libft.h"

char	*fp_strcpyto(char *str, int c)
{
	char	*output;
	int		i;

	if (!str)
		return (NULL);
	output = (char *)fp_calloc(fp_strlen(str) + 1, sizeof(char));
	if (!output)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != c)
		output[i] = str[i];
	return (output);
}
