/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:11:52 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 07:58:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"
#include <stddef.h>

unsigned int ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return 0;
	return 1 + ft_list_size(begin_list->next);
}
