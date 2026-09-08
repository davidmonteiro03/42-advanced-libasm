/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:01:53 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 08:17:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester_bonus.h"

static bool check_list_sort(const t_larray *const larr)
{
	if (larr == NULL || larr->alloc_fct == NULL || larr->cmp_fct == NULL)
		return true;
	t_list *list = NULL;
	for (size_t i = 0; i < larr->size; i++)
		list_push_front(&list, (*(larr->alloc_fct))(larr->data + i * larr->elem_size));
	ft_list_sort(&list, larr->cmp_fct);
	bool result = true;
	for (t_list *node = list; node != NULL && node->next != NULL; node = node->next)
		result = result && ((*(larr->cmp_fct))(node->data, node->next->data) <= 0);
	list_clear(&list, larr->free_fct);
	return result;
}

void test_list_sort(void)
{
	function_info(__func__ + 5);
	for (size_t i = 0; i < g_larrs_size; i++)
	{
		if (i > 0)
			fprintf_and_fflush(stdout, " ");
		(check_list_sort(g_larrs + i) == true) ? test_passed()
											   : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
