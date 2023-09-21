/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:13:07 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/21 11:35:04 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	precision_zero(char *flags, va_list args)
{
	if (flags[2] == '0')
	{
		if (flags[3] == 's')
			va_arg(args, char *);
		else
			va_arg(args, int);
	}
	if (fp_isalpha(flags[2]))
	{
		if (flags[2] == 's')
			va_arg(args, char *);
		else
			va_arg(args, int);
	}
}

static int	fp_flag_width(char *flags)
{
	int		i;
	int		width;
	char	*temp;

	i = 2;
	while (fp_isdigit(flags[i]))
		i++;
	temp = fp_strndup(&flags[2], i);
	width = fp_atoi(temp);
	free(temp);
	return (width);
}

int	fp_precision(char *flags, va_list args)
{
	int		width;
	int		output;
	int		i;
	char	*temp;

	i = 0;
	if (flags[2] == '0' || fp_isalpha(flags[2]))
	{
		precision_zero(flags, args);
		return (0);
	}
	while (fp_isdigit(flags[i]))
		i++;
	width = fp_flag_width(flags);
	if (fp_strchr(&flags[i], 's'))
	{
		temp = fp_strndup(va_arg(args, char *), width);
		output = fp_putstr_and_len(temp, 1);
		free(temp);
	}
	else
		output = fp_fill_right(flags, args, '0');
	return (output);
}
