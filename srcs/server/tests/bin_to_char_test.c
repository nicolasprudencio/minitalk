/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_char_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:00:11 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/22 17:13:43 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minunit.h>
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

MU_TEST(test_bin_to_char_conversion)
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
	output = bin_to_char(&front);
	printf("converted char: %c\n", output);
	mu_check(output == 'A');
}

MU_TEST_SUITE(conversion_test)
{
	MU_RUN_TEST(test_bin_to_char_conversion);
}

int main(void)
{	
	MU_RUN_SUITE(conversion_test);	
}