/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_sig_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:06:32 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/22 19:34:28 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minunit.h>
#include <signal.h>
#include "queue.h"

t_queue	*front = NULL;

void	handle_signals(int signal)
{
	if (signal == SIGUSR1)
		enqueue_pre_alloc(&front, 1);
	if (signal == SIGUSR2)
		enqueue_pre_alloc(&front, 0);
}

MU_TEST(signal_test)
{
	char	c = 'A';
	struct sigaction	*action = NULL;
	pid_t	pid;
	char	output;
	
	action = (struct sigaction *)fp_calloc(1, sizeof(struct sigaction));
	action->sa_handler = handle_signals;
	sigemptyset(&action->sa_mask);
	action->sa_flags = 0;
	pid = getpid();
	sigaction(SIGUSR1, action, NULL);
	sigaction(SIGUSR2, action, NULL);
	char_to_sig(c, pid);
	output = bin_to_char(&front);
	printf("bin to sig output: %c\n", output);
	mu_check(output == 'A');
}

MU_TEST_SUITE(test_if_signal_has_been_send_correctly)
{
	MU_RUN_TEST(signal_test);
}

int	main(void)
{
	MU_RUN_SUITE(test_if_signal_has_been_send_correctly);
}