/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:19:31 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/21 15:49:29 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

MU_TEST(test_check)
{
	mu_check(ft_tobin('c') == 0);
}
MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[])
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}