/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_grdfre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:20:08 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 09:58:02 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fp_grdfre(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		free(grid[i]);
	free(grid);
}

void	fp_grdfre3(char ***grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		fp_grdfre(grid[i]);
	free(grid);
}
