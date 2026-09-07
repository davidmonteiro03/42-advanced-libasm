/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:16:02 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 10:47:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_strlen(const t_array *const s)
{
	if (s == NULL || s->data == NULL)
		return true;
	const size_t expected = strlen(s->data);
	const size_t provided = ft_strlen(s->data);
	return expected == provided;
}

void test_strlen(void)
{
	function_info(__func__ + 5);
	for (size_t i = 0; i < g_strs_size; i++)
	{
		if (i > 0)
			fprintf_and_fflush(stdout, " ");
		(check_strlen(g_strs + i) == true) ? test_passed()
										   : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
