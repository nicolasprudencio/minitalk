/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:12:00 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 14:33:54 by nprudenc         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	*bin;
	int	i;
	int	j;
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
		fp_printf("bin_str: %s\n", bin);
		j = 0;
		while (bin[j])
		{
			usleep(300);
			if (connection == 1)
			{
				if (bin[j] == '0')
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				j++;
				connection = 0;
			}
		}
		free(bin);
	}
	return (0);
}
