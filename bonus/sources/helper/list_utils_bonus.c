/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 07:18:13 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 09:16:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester_bonus.h"

void list_push_front(t_list **const begin_list, void *const data)
{
	if (begin_list == NULL)
		return;
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return;
	new_node->data = data;
	new_node->next = *begin_list;
	*begin_list = new_node;
}

void list_clear(t_list **const begin_list, void (*const free_fct)(void *))
{
	if (begin_list == NULL || *begin_list == NULL)
		return;
	t_list *next = (*begin_list)->next;
	if (free_fct != NULL)
		(*free_fct)((*begin_list)->data);
	free(*begin_list);
	*begin_list = next;
	list_clear(begin_list, free_fct);
}
