/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:15:25 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:06:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_strcmp(const t_array *const s1, const t_array *const s2)
{
	if (s1 == NULL || s2 == NULL || s1->data == NULL || s2->data == NULL)
		return true;
	const int expected = strcmp(s1->data, s2->data);
	const int provided = ft_strcmp(s1->data, s2->data);
	return (expected == 0) == (provided == 0) &&
		   (expected >= 0) == (provided >= 0) &&
		   (expected <= 0) == (provided <= 0) &&
		   (expected > 0) == (provided > 0) &&
		   (expected < 0) == (provided < 0);
}

void test_strcmp(void)
{
	function_info(__func__ + 5);
	bool first_test = true;
	for (size_t i = 0; i < g_strs_size; i++)
	{
		for (size_t k = 0; k < g_strs_size; k++)
		{
			if (first_test == false)
				fprintf_and_fflush(stdout, " ");
			(check_strcmp(g_strs + i, g_strs + k) == true) ? test_passed()
														   : test_failed();
			first_test = false;
		}
	}
	fprintf_and_fflush(stdout, "\n");
}
