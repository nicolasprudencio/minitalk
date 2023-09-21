/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:03:41 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/26 15:51:03 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_putnbr_un(unsigned int nb)
{
	if (nb > 9)
	{
		fp_putnbr_un(nb / 10);
		fp_putnbr_un(nb % 10);
	}
	if (nb <= 9)
		fp_putchar_fd(nb + 48, 1);
	return (fp_strlen(fp_itoa(nb)) - 1);
}
