/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:01:51 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 07:56:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester_bonus.h"

static bool check_list_size(const t_larray *const larr)
{
	if (larr == NULL || larr->alloc_fct == NULL)
		return true;
	t_list *list = NULL;
	for (size_t i = 0; i < larr->size; i++)
		list_push_front(&list, (*(larr->alloc_fct))(larr->data + i * larr->elem_size));
	const unsigned int expected = larr->size;
	const unsigned int provided = ft_list_size(list);
	list_clear(&list, larr->free_fct);
	return expected == provided;
}

void test_list_size(void)
{
	function_info(__func__ + 5);
	for (size_t i = 0; i < g_larrs_size; i++)
	{
		if (i > 0)
			fprintf_and_fflush(stdout, " ");
		(check_list_size(g_larrs + i) == true) ? test_passed()
											   : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
