#include "libft.h"

int	st_free(char ***ccc, char **cc);

int	main(int argc, char **argv)
{
	char	***ccc;
	char		**cc;
	int			i;
	int			j;

	if (argc != 4)
		return (0);
	cc = fp_split(argv[1], argv[2][0]);
	ccc = fp_splitsplit(argv[1], argv[2][0], argv[3][0]);
	if (!cc || !ccc)
		return (st_free(ccc, cc));
	i = -1;
	while (cc[++i])
		fp_printf("%s\n", cc[i]);
	i = -1;
	while (ccc[++i])
	{
		j = -1;
		while (ccc[i][++j])
			fp_printf("%15s", ccc[i][j]);
		write(1, "\n", 1);
	}
	st_free(ccc,cc);
	return (0);
}

int	st_free(char ***ccc, char **cc)
{
	int	i;

	if (ccc)
	{
		i = -1;
		while (ccc[++i])
			fp_grdfre(ccc[i]);
		free(ccc);
	}
	if (cc)
		fp_grdfre(cc);
	return (1);
}
