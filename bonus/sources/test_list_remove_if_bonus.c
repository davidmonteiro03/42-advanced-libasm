/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:01:49 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 17:50:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester_bonus.h"

static bool check_list_remove_if(t_list **const begin_list, void *const data_ref, int (*const cmp)(), void (*const free_fct)(void *))
{
	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
		return true;
	ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
	for (t_list *node = *begin_list; node != NULL; node = node->next)
		if ((*cmp)(node->data, data_ref) == 0)
			return false;
	return true;
}

void test_list_remove_if(void)
{
	function_info(__func__ + 5);
	bool first_test = true;
	for (size_t i = 0; i < g_larrs_size; i++)
	{
		if (g_larrs[i].alloc_fct == NULL)
			continue;
		void *first = NULL, *middle = NULL, *last = NULL;
		t_list *list = NULL;
		for (size_t k = 0; k < g_larrs[i].size; k++)
		{
			if (i == 0)
				first = (void *)(g_larrs[i].data + k * g_larrs[i].elem_size);
			else if (i == g_larrs[i].size / 2 && g_larrs[i].size % 2 == 1)
				middle = (void *)(g_larrs[i].data + k * g_larrs[i].elem_size);
			else if (i == g_larrs[i].size - 1)
				last = (void *)(g_larrs[i].data + k * g_larrs[i].elem_size);
			list_push_front(&list, (*(g_larrs[i].alloc_fct))(g_larrs[i].data + k * g_larrs[i].elem_size));
		}
		if (first_test == false)
			fprintf_and_fflush(stdout, " ");
		(check_list_remove_if(&list, first, g_larrs[i].cmp_fct, g_larrs[i].free_fct) == true) ? test_passed()
																							  : test_failed();
		first_test = false;
		fprintf_and_fflush(stdout, " ");
		(check_list_remove_if(&list, middle, g_larrs[i].cmp_fct, g_larrs[i].free_fct) == true) ? test_passed()
																							   : test_failed();
		fprintf_and_fflush(stdout, " ");
		(check_list_remove_if(&list, last, g_larrs[i].cmp_fct, g_larrs[i].free_fct) == true) ? test_passed()
																							 : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
