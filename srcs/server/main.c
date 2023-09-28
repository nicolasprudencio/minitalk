/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:11:49 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 19:25:41 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	handle_signal(int signal, siginfo_t *info, void *context);

t_queue	*front;

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;
	char				c;

	front = NULL;
	action.sa_sigaction = (void *)handle_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	fp_printf("server PID: %d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		if (queue_len(&front) >= 8)
		{
			c = dequeue_bin(&front);
			fp_putchar_fd(c, 1);
		}
	}
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	usleep(10);
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		enqueue_pre_alloc(&front, 1);
		usleep(10);
		kill(client_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		enqueue_pre_alloc(&front, 0);
		usleep(10);
		kill(client_pid, SIGUSR1);
	}
	else
		fp_printf("No signal received\n");
	context = NULL;
}
