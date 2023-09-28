/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:12:00 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 18:32:11 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <signal.h>

static int	connection = 1;

static void	st_observer(int sig)
{
	usleep(100);
	if (sig == SIGUSR1)
		connection = 1;
}

static void	st_set_handler(struct sigaction *action)
{
	sigemptyset(&action->sa_mask);
	action->sa_handler = st_observer;
	action->sa_flags = 0;
	sigaction(SIGUSR1, action, NULL);
}

static void	st_send_bin(char *bin, pid_t pid)
{
	int	j;
	int	timeout;

	j = 0;
	timeout = 0;
	while (bin[j])
	{
		timeout = 0;
		if (connection == 1)
		{
			if (bin[j] == '0')
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j++;
			connection = 0;
		}
		while (connection == 0)
		{
			timeout++;
			usleep(100);
			if (timeout > 1000)
				connection = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	char	*bin;
	int	i;
	pid_t	pid;
	struct sigaction	action;

	if (argc != 3)
		return (1);
	st_set_handler(&action);
	pid = atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
	{
		bin = char_to_bin(argv[2][i]);
		if (!bin)
			return (1);
		st_send_bin(bin, pid);
		free(bin);
	}
	return (0);
}

