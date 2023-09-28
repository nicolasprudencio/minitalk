/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:10:05 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 13:57:34 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"
#include <minunit.h>

MU_TEST(test_dequeue_output_fauna)
{
	t_queue	*front;
	int		output;

	front = NULL;
	for (int i = 0; i < 2000; i++)
		enqueue_pre_alloc(&front, i);
	int i = 0;
	while (front)
	{
		output = dequeue(&front);
		mu_check(output == i);
		i++;
	}
}

MU_TEST(test_dequeue_output_nikko)
{
	t_queue	*front;
	int		output;

	front = NULL;
	for (int i = 0; i < 2000; i++)
		enqueue_pre_alloc(&front, i);
	int i = 0;
	while (front)
	{
		output = dequeue_nikko(&front);
		mu_check(output == i);
		i++;
	}
}


MU_TEST(test_first_pos_ref_fauna)
{	
	t_queue	*front;

	front = NULL;
	enqueue_pre_alloc(&front, 30);
	enqueue_pre_alloc(&front, 35);
	dequeue(&front);
	mu_check(front->bin == 35);
	dequeue(&front);
	mu_check(front == NULL);
}

MU_TEST(test_first_pos_ref_nikko)
{	
	t_queue	*front;

	front = NULL;
	enqueue_alloc_onreq(&front, 30);
	enqueue_alloc_onreq(&front, 35);
	dequeue_nikko(&front);
	mu_check(front->bin == 35);
	dequeue_nikko(&front);
	mu_check(front == NULL);
}
MU_TEST_SUITE(dequeue_suit)
{
	MU_RUN_TEST(test_dequeue_output_fauna);
	MU_RUN_TEST(test_dequeue_output_nikko);
	MU_RUN_TEST(test_first_pos_ref_fauna);
	MU_RUN_TEST(test_first_pos_ref_nikko);
}

int main(void)
{
	MU_RUN_SUITE(dequeue_suit);
	MU_REPORT();
	return (0);
}
// MU_TEST(test_dequeue_output)
// {
// 	t_queue	*front;
// 	t_queue	*temp;

// 	front = NULL;
// 	for (int i = 0; i < 20; i++)
// 		enqueue_alloc_onreq(&front, i);
	
// }