/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:56:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/02 08:57:06 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*g_front;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	pid_t	client_pid;
	int		retries;
	char	c;

	retries = 0;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		usleep(30);
		enqueue(&g_front, 1);
		kill(client_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		usleep(30);
		enqueue(&g_front, 0);
		kill(client_pid, SIGUSR1);
	}
	c = dequeue_limit(&g_front, 8);
	if (c != -1)
		write(1, &c, 1);
	context = NULL;
}

static void	st_set_handlers(struct sigaction *action)
{
	action->sa_sigaction = (void *)handle_signal;
	sigemptyset(&action->sa_mask);
	action->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, action, NULL);
	sigaction(SIGUSR2, action, NULL);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	g_front = NULL;
	st_set_handlers(&action);
	pid = getpid();
	fp_printf("server PID: %d\n", pid);
	while (1)
		;
}
