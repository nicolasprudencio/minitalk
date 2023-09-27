/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:21:46 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 13:09:46 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	main(int argc, char *argv[])
{	
	pid_t	pid;

	if (argc != 2)
	{
		printf("Error: Invalid file pid declaration!");
		return (1);
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR2);
}

