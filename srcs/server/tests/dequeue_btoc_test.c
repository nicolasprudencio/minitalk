/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_btoc_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:06:32 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/27 21:33:26 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minunit.h>
#include <signal.h>
#include "queue.h"

MU_TEST(test_dequeue_btoc_conversion)
{
	t_queue *front;
	char	output;

	front = NULL;
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 1);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 1);
	output = dequeue_btoc(&front);
	mu_check(output == 'A');
}


MU_TEST(test_if_bin_string_is_correct)
{
	char	c;
	t_queue	*front;

	front = NULL;
	enqueue_char('a', &front);
	enqueue_char('b', &front);
	enqueue_char('c', &front);
	enqueue_char('d', &front);
	enqueue_char('e', &front);
	

	c = dequeue_btoc(&front);
	mu_check(c = 'a');
	printf("found char: %c\n", c);
	c = dequeue_btoc(&front);
	mu_check(c = 'b');
	printf("found char: %c\n", c);
	c = dequeue_btoc(&front);
	mu_check(c = 'c');
	printf("found char: %c\n", c);
	c = dequeue_btoc(&front);
	mu_check(c = 'd');
	printf("found char: %c\n", c);
	c = dequeue_btoc(&front);
	mu_check(c = 'e');
	printf("found char: %c\n", c);
}

MU_TEST(test_incorrect_queue_len)
{
	t_queue *front;
	char	output;

	front = NULL;
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 1);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	enqueue_pre_alloc(&front, 0);
	output = dequeue_btoc(&front);
	mu_check(output == -1);
}


MU_TEST_SUITE(test_dequeue_btoc)
{
	MU_RUN_TEST(test_if_bin_string_is_correct);
	MU_RUN_TEST(test_dequeue_btoc_conversion);
	MU_RUN_TEST(test_incorrect_queue_len);
}

int	main(void)
{
	MU_RUN_SUITE(test_dequeue_btoc);
	MU_REPORT();
}