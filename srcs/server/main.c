/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:11:49 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 16:30:32 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*front;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	pid_t	client_pid;
	int		retries;
	char	c;

	retries = 0;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		usleep(10);
		enqueue_pre_alloc(&front, 1);
		kill(client_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		usleep(10);
		enqueue_pre_alloc(&front, 0);
		kill(client_pid, SIGUSR1);
	}
	c = dequeue_limit(&front, 8);
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

	front = NULL;
	st_set_handlers(&action);
	pid = getpid();
	fp_printf("server PID: %d\n", pid);
	while (1)
		;
}
