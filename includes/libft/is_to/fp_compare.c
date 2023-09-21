#include "libft.h"

int	fp_compare(int c, int quantity, ...)
{
	va_list	args;
	int	i;

	i = 1;
	va_start(args, quantity);
	while ((i - 1) < quantity)
	{
		if (va_arg(args, int) == c)
			return (i);
	}
	return (0);
}
