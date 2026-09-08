/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:15:08 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 09:09:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"
#include <stddef.h>
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
		return;
	for (t_list *prev = NULL, *curr = *begin_list, *next = NULL; curr != NULL; curr = next)
	{
		next = curr->next;
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			(prev == NULL) ? (*begin_list = curr->next)
						   : (prev->next = curr->next);
			if (free_fct != NULL)
				(*free_fct)(curr->data);
			free(curr);
		}
		else
			prev = curr;
	}
}
