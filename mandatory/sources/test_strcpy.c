/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:15:41 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:51:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_strcpy(const t_array *const dest, const t_array *const src)
{
	if (dest == NULL || src == NULL || dest->data == NULL || src->data == NULL)
		return true;
	const size_t max_size = MAX(dest->size, src->size);
	char expected_dest[max_size];
	char provided_dest[max_size];
	memset(expected_dest, 0, max_size);
	memset(provided_dest, 0, max_size);
	memcpy(expected_dest, dest->data, dest->size);
	memcpy(provided_dest, dest->data, dest->size);
	const char *const expected = strcpy(expected_dest, src->data);
	const char *const provided = ft_strcpy(provided_dest, src->data);
	return ((expected == expected_dest) == (provided == provided_dest)) &&
		   ((expected == NULL) == (provided == NULL)) &&
		   ((strcmp(expected_dest, src->data) == 0) == (strcmp(provided_dest, src->data) == 0)) &&
		   ((strcmp(expected_dest, expected) == 0) == (strcmp(provided_dest, provided) == 0)) &&
		   ((strcmp(src->data, expected_dest) == 0) == (strcmp(src->data, provided_dest) == 0)) &&
		   ((strcmp(src->data, expected) == 0) == (strcmp(src->data, provided) == 0)) &&
		   ((strcmp(expected, expected_dest) == 0) == (strcmp(provided, provided_dest) == 0)) &&
		   ((strcmp(expected, src->data) == 0) == (strcmp(provided, src->data) == 0)) &&
		   ((memcmp(expected_dest, src->data, max_size) == 0) == (memcmp(provided_dest, src->data, max_size) == 0)) &&
		   ((memcmp(expected_dest, expected, max_size) == 0) == (memcmp(provided_dest, provided, max_size) == 0)) &&
		   ((memcmp(src->data, expected_dest, max_size) == 0) == (memcmp(src->data, provided_dest, max_size) == 0)) &&
		   ((memcmp(src->data, expected, max_size) == 0) == (memcmp(src->data, provided, max_size) == 0)) &&
		   ((memcmp(expected, expected_dest, max_size) == 0) == (memcmp(provided, provided_dest, max_size) == 0)) &&
		   ((memcmp(expected, src->data, max_size) == 0) == (memcmp(provided, src->data, max_size) == 0));
}

/* 01 02 10 12 20 21  */

void test_strcpy(void)
{
	function_info(__func__ + 5);
	bool first_test = true;
	for (size_t i = 0; i < g_strs_size; i++)
	{
		for (size_t k = 0; k < g_strs_size; k++)
		{
			if (first_test == false)
				fprintf_and_fflush(stdout, " ");
			(check_strcpy(g_strs + i, g_strs + k) == true) ? test_passed()
														   : test_failed();
			first_test = false;
		}
	}
	fprintf_and_fflush(stdout, "\n");
}
