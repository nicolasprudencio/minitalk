/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:00:11 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/28 16:11:47 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minunit.h>
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

MU_TEST(test_if_bin_number_is_correct)
{
	char	*bin;
	char	*A = "01000001";
	char	*B = "01000010";
	char	*C = "01000011";
	char	*D = "01000100";

	bin = char_to_bin('A');
	mu_check(A = bin);
	printf("found bin: %s\n", bin);
	bin = char_to_bin('B');
	mu_check(B = bin);
	printf("found bin: %s\n", bin);
	bin = char_to_bin('C');
	mu_check(C = bin);
	printf("found bin: %s\n", bin);
	bin = char_to_bin('D');
	mu_check(D = bin);
	printf("found bin: %s\n", bin);
	free(bin);
}

MU_TEST_SUITE(conversion_test)
{
	MU_RUN_TEST(test_if_bin_number_is_correct);
}

int main(void)
{	
	MU_RUN_SUITE(conversion_test);
	MU_REPORT();
}