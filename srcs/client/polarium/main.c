/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:12:00 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 16:13:01 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "queue.h"

int	main(int argc, char **argv)
{
	int	i = -1;

	if (argc != 3)
		return (1);
	pid_t	pid = atoi(argv[1]);
	while (argv[2][++i])
	{
		char_to_sig(argv[2][i], pid);
	}
	return (0);
}
