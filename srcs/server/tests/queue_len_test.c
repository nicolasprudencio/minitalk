/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_len_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:21:20 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/22 17:31:05 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minunit.h>
#include <queue.h>

MU_TEST(queue_len_test)
{
	t_queue	*front;
	size_t	len;

	front = NULL;
	for (int i = 0; i < 20; i++)
	{
		enqueue_pre_alloc(&front, i);
	}
	len = queue_len(&front);
	mu_check(len == 20);
}

MU_TEST_SUITE(queue_len_suite)
{
	MU_RUN_TEST(queue_len_test);
}

int	main(void)
{
	MU_RUN_SUITE(queue_len_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}