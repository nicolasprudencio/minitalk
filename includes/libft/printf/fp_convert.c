/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:18:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/21 11:39:17 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_convert(char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (fp_putnbr_base(va_arg(args, int), 10, 0));
	else if (c == 's')
		return (fp_putstr_and_len(va_arg(args, char *), 1));
	else if (c == 'c')
		return (fp_putchar_fd(va_arg(args, int), 1));
	else if (c == 'x')
		return (fp_putnbr_base(va_arg(args, unsigned int), 16, 0));
	else if (c == 'X')
		return (fp_putnbr_base(va_arg(args, unsigned int), 16, 1));
	else if (c == 'u')
		return (fp_putnbr_base(va_arg(args, unsigned int), 10, 0));
	else if (c == 'p')
		return (fp_putpointer(va_arg(args, void *)));
	return (0);
}
