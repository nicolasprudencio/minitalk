#include "libft.h"

int	fp_isprime(int nb)
{
	int	i;

	i = 1;
	while (++i < nb)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
