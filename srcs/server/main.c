/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:11:49 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/20 18:21:00 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	print_sig(int signal);

int	main(void)
{
	struct sigaction	*action1;
	pid_t				pid;

	action1->sa_handler = print_sig;
	sigemptyset(&action1->sa_mask);
	action1->sa_flags = 0;
	pid = getpid();
	printf("server PID: %d\n", pid);
	sigaction(SIGUSR1, action1, NULL);
	sigaction(SIGUSR2, action1, NULL);
	while (1)
		;
}		

void	print_sig(int signal)
{
	if (signal == SIGUSR1)
		printf("SIGUSR1 received\n");
	else if (signal == SIGUSR2)
		printf("SIGUSR2 received\n");
	else
		printf("No signal received\n");
}
