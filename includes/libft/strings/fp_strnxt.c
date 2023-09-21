#include "libft.h"

char	*fp_strnxt(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] && s[i] != (char) c)
		;
	if (s[i] && s[i + 1] && s[i] == (char)c)
		return ((char *)&s[i + 1]);
	return (NULL);
}
