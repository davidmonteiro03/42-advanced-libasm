/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:15:47 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 15:48:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_strdup(const t_array *const s)
{
	if (s == NULL || s->data == NULL)
		return true;
	char *const expected = strdup(s->data);
	char *const provided = ft_strdup(s->data);
	const bool result = ((expected == s->data) == (provided == s->data)) &&
						((expected == NULL) == (provided == NULL)) &&
						((strcmp(s->data, expected) == 0) == (strcmp(s->data, provided) == 0)) &&
						((strcmp(expected, s->data) == 0) == (strcmp(provided, s->data) == 0));
	if (provided != NULL && provided != s->data)
		free(provided);
	if (expected != NULL && expected != s->data)
		free(expected);
	return result;
}

void test_strdup(void)
{
	function_info(__func__ + 5);
	for (size_t i = 0; i < g_strs_size; i++)
	{
		if (i > 0)
			fprintf_and_fflush(stdout, " ");
		(check_strdup(g_strs + i) == true) ? test_passed()
										   : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
