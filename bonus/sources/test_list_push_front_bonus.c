/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_front_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:02:02 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/11 12:39:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester_bonus.h"

static bool check_list_push_front(t_list **const begin_list, void *const data)
{
	if (begin_list == NULL)
		return true;
	t_list *old_head = *begin_list;
	ft_list_push_front(begin_list, data);
	if (*begin_list == old_head)
		return false;
	return *begin_list == NULL || ((*begin_list)->data == data && (*begin_list)->next == old_head);
}

void test_list_push_front(void)
{
	function_info(__func__ + 5);
	bool first_test = true;
	for (size_t i = 0; i < g_larrs_size; i++)
	{
		if (g_larrs[i].alloc_fct == NULL)
			continue;
		t_list *list = NULL;
		for (size_t k = 0; k < g_larrs[i].size; k++)
		{
			if (first_test == false)
				fprintf_and_fflush(stdout, " ");
			(check_list_push_front(&list, (*(g_larrs[i].alloc_fct))(g_larrs[i].data + k * g_larrs[i].elem_size)) == true) ? test_passed()
																														  : test_failed();
			first_test = false;
		}
		list_clear(&list, g_larrs[i].free_fct);
	}
	fprintf_and_fflush(stdout, "\n");
}
