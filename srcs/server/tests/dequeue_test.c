/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:10:05 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/21 20:14:36 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"
#include <minunit.h>

MU_TEST(tests_dequeue_output_fauna)
{
	t_queue	*front;
	int		output;

	front = NULL;
	for (int i = 0; i < 20; i++)
		enqueue_pre_alloc(&front, i);
	int i = 0;
	while (front)
	{
		output = dequeue_nikko(front);
		mu_check(output == i);
		i++;
	}
}

MU_TEST_SUITE(dequeue_suit)
{
	MU_RUN_TEST(tests_dequeue_output_fauna);
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