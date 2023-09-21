#include "libft.h"

int	fp_ishighest(int quantity, ...)
{
	va_list	args;
	int	output;
	int	i;
	int	temp;

	i = 0;
	va_start(args, quantity);
	output = va_arg(args, int);
	while (i < quantity)
	{
		temp = va_arg(args, int);
		if (temp > output)
			output = temp;
	}
	va_end(args);
	return (output);
}
