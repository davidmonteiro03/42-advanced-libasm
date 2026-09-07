/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:51:33 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:08:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester_bonus.h"

static bool check_atoi_base(const char *const str, const char *const base)
{
	if (str == NULL || base == NULL)
		return true;
	const int expected = atoi_base(str, base);
	const int provided = ft_atoi_base((char *)str, (char *)base);
	return expected == provided;
}

void test_atoi_base(void)
{
	function_info(__func__ + 5);
	bool first_test = true;
	for (size_t i = 0; i < g_strs_size; i++)
	{
		const char *const *const strs = (const char *const *const)g_strs[i].data;
		for (size_t k = 0; k < g_strs[i].size; k++)
		{
			for (size_t l = 0; l < g_bases_size; l++)
			{
				const char *const *const bases = (const char *const *const)g_bases[l].data;
				for (size_t m = 0; m < g_bases[l].size; m++)
				{
					if (first_test == false)
						fprintf_and_fflush(stdout, " ");
					(check_atoi_base(strs[k], bases[m]) == true) ? test_passed()
																 : test_failed();
					first_test = false;
				}
			}
		}
	}
	fprintf_and_fflush(stdout, "\n");
}
