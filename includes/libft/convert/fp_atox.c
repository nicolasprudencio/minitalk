/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:30:00 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/14 12:32:05 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	fp_atox(char *s)
{
	int			power;
	int			i;
	unsigned int	output;

	if (!s)
		return (0xFFFFFF);
	output = 0;
	if (s[0] != '0' || s[1] != 'x')
		return (output);
	i = 1;
	power = fp_strlen(s) - 3;
	while (s[++i])
	{
		if (fp_isdigit(s[i]))
			output += (s[i] - 48) * pow(16, power);
		if (fp_isupper(s[i]))
			output += (s[i] - 55) * pow(16, power);
		else
			output += (s[i] - 87) * pow(16, power);
		power--;
	}
	return (output);
}
