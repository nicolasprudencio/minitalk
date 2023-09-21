/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:34:45 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/21 20:12:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "queue.h"
#include <minunit.h>

 MU_TEST(enqueue_pre_alloc_test)
 {
 	t_queue	*front;
 	t_queue	*front2;
 	t_queue *temp;

 	front = NULL;
 	for (int i = 0; i < 2000; i++)
 		enqueue_pre_alloc(&front, i);
 	front2 = (t_queue *)fp_calloc(1, sizeof(t_queue));
 	for (int i = 0; i < 20; i++)
 		enqueue_pre_alloc(&front2, i);
 	temp = front;
 	for (int i = 0; i< 2000; i++)
 	{
 		mu_check(temp->bin == i);
 		temp = temp->next;
 	}
 	temp = front2;
 	enqueue_pre_alloc(&front2, 30);
 	while (temp->next)
 		temp = temp->next;
 	mu_check(temp->bin == 30);
 }

MU_TEST(check_if_enqueue_pre_alloc_works_with_a_free_pointer)
{
	t_queue *front;
	t_queue	*temp;

	front = fp_calloc(1, sizeof(t_queue));
	free(front);
	front = NULL;
	for (int i = 0; i < 10; i++)
	{
		enqueue_pre_alloc(&front, i);
	}
	temp = front;
	for (int i = 0; i < 10; i++)
	{
		mu_check(temp->bin == i);
		temp = temp->next;
	}
}

MU_TEST(check_if_enqueue_alloc_onreq_works_with_a_free_pointer)
{
	t_queue *front;
	t_queue	*temp;

	front = fp_calloc(1, sizeof(t_queue));
	free(front);
	front = NULL;
	for (int i = 0; i < 10; i++)
		enqueue_alloc_onreq(&front, i);
	temp = front;
	for (int i = 0; i < 10; i++)
	{
		mu_check(temp->bin == i);
		temp = temp->next;
	}
}

MU_TEST(enqueue_alloc_onreq_test)
{
	t_queue	*front;
	t_queue	*front2;
	t_queue *temp;

	front = NULL;
	for (int i = 0; i < 2000; i++)
		enqueue_alloc_onreq(&front, i);
	temp = front;
	for (int i = 0; i < 2000; i++)
	{
		mu_check(temp->bin == i);
		temp = temp->next;
	}
	front2 = (t_queue *)fp_calloc(1, sizeof(t_queue));
	for (int i = 0; i < 20; i++)
		enqueue_alloc_onreq(&front2, i);
	enqueue_alloc_onreq(&front2, 35);
	temp = front2;	
	while (temp->next)
		temp = temp->next;
	mu_check(temp->bin == 35);

}

MU_TEST_SUITE(queue_suit)
{
	MU_RUN_TEST(enqueue_pre_alloc_test);
	MU_RUN_TEST(enqueue_alloc_onreq_test);
	MU_RUN_TEST(check_if_enqueue_pre_alloc_works_with_a_free_pointer);
	MU_RUN_TEST(check_if_enqueue_alloc_onreq_works_with_a_free_pointer);
}

int main(void)
{
	MU_RUN_SUITE(queue_suit);
	MU_REPORT();
	return (MU_EXIT_CODE);
}