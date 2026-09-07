/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:12:58 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 15:47:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_calloc(const size_t nmemb, const size_t size)
{
	void *const expected = calloc(nmemb, size);
	void *const provided = ft_calloc(nmemb, size);
	bool result = (expected == NULL) == (provided == NULL);
	if (expected != NULL && provided != NULL)
		result = result && (memcmp(expected, provided, nmemb * size) == 0);
	if (provided != NULL)
		free(provided);
	if (expected != NULL)
		free(expected);
	return result;
}

void test_calloc(void)
{
	function_info(__func__ + 5);
	const size_t amounts[] = {
		0,
		sizeof(char),
		sizeof(int),
		sizeof(float),
		sizeof(double),
		LLONG_MAX,
	};
	const size_t amounts_size = ARRAY_SIZE(amounts);
	bool first_test = true;
	for (size_t i = 0; i < amounts_size; i++)
	{
		for (size_t k = 0; k < amounts_size; k++)
		{
			if (first_test == false)
				fprintf_and_fflush(stdout, " ");
			(check_calloc(amounts[i], amounts[k]) == true) ? test_passed()
														   : test_failed();
			first_test = false;
		}
	}
	fprintf_and_fflush(stdout, "\n");
}
