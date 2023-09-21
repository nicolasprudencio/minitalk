/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:34:45 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/21 18:28:53 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "queue.h"
#include <minunit.h>

MU_TEST(enqueue_pre_alloc_test)
{
	t_queue	*front;
	t_queue *temp;

	front = (t_queue *)fp_calloc(1, sizeof(t_queue));
	for (int i = 0; i < 4; i++)
		enqueue_pre_alloc(front, i);
	temp = front;
	for (int i = 0; i< 4; i++)
	{
		mu_check(temp->bin == i);
		temp = temp->next;
	}
}

MU_TEST(enqueue_alloc_onreq_test)
{
	t_queue	*front;
	t_queue *temp;

	front = (t_queue *)fp_calloc(1, sizeof(t_queue));
	for (int i = 0; i < 4; i++)
		enqueue_alloc_onreq(front, i);
	temp = front;
	for (int i = 0; i< 4; i++)
	{
		mu_check(temp->bin == i);
		temp = temp->next;
	}
}

MU_TEST_SUITE(queue_suit)
{
	MU_RUN_TEST(enqueue_pre_alloc_test);
	MU_RUN_TEST(enqueue_alloc_onreq_test);
}

int main(void)
{
	MU_RUN_SUITE(queue_suit);
	MU_REPORT();
	return (MU_EXIT_CODE);
}