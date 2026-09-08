/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:14:26 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 09:04:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"
#include <stdlib.h>

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
		return;
	for (t_list *node = *begin_list; node != NULL && node->next != NULL;)
	{
		if ((*cmp)(node->data, node->next->data) > 0)
		{
			void *tmp = node->data;
			node->data = node->next->data;
			node->next->data = tmp;
			node = *begin_list;
		}
		else
			node = node->next;
	}
}
