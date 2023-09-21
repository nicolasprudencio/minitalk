/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_new_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:54:34 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/01 20:26:33 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	st_relate_center(t_wireframe **wrfrm, int width, int height);
static void	st_relate_sides(t_wireframe **wrfrm, int width, int height);

t_wireframe	**fp_frmnew(int width, int height)
{
	t_wireframe	**wrfrm;
	int		i;

	wrfrm = (t_wireframe **)fp_calloc(height + 1, sizeof(t_wireframe *));
	i = 0;
	while (i < height)
	{
		wrfrm[i] = (t_wireframe *)fp_calloc(width + 1, sizeof(t_wireframe));
		i++;
	}
	st_relate_center(wrfrm, width, height);
	st_relate_sides(wrfrm, width, height);
	wrfrm[0][0].width = width;
	wrfrm[0][0].height = height;
	return (wrfrm);
}

void	fp_frmfre(t_wireframe **wrfrm)
{
	int	y;
	int	width;

	width = wrfrm[0][0].width;
	y = -1;
	while (++y < width)
		free(wrfrm[y]);
	free(wrfrm);
}

static void	st_relate_center(t_wireframe **wrfrm, int width, int height)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (y != height - 1)
				wrfrm[y][x].yplus = &wrfrm[y + 1][x];
			if (y != 0)
				wrfrm[y][x].ymins = &wrfrm[y - 1][x];
			if (x != width - 1)
				wrfrm[y][x].xplus = &wrfrm[y][x + 1];
			if (x != 0)
				wrfrm[y][x].xmins = &wrfrm[y][x - 1];
		}
	}
}

static void	st_relate_sides(t_wireframe **wrfrm, int width, int height)
{
	int	i;

	i = -1;
	while (++i < width)
	{
		wrfrm[0][i].ymins = &wrfrm[height - 1][i];
		wrfrm[height - 1][i].yplus = &wrfrm[0][i];
	}
	i = -1;
	while (++i < height)
	{
		wrfrm[i][0].xmins = &wrfrm[i][width - 1];
		wrfrm[i][width -1].xplus = &wrfrm[i][0];
	}
}
