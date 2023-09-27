/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:11:49 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 16:52:17 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	handle_signal(int signal, siginfo_t *info, void *context);


int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	action.sa_sigaction = (void *)handle_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("server PID: %d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		if (queue_len(&front) >= 8)
		{
			char c = bin_to_char(&front);
			fp_putchar_fd(c, 1);
		}
	}
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	client_pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		kill(client_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		kill(client_pid, SIGUSR1);
	}
	else
		fp_printf("No signal received\n");
	context = NULL;
}
