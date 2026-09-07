/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:12:17 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:30:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s)
{
	const size_t s_size = ft_strlen(s);
	char *result = (char *)malloc(sizeof(char) * (s_size + 1));
	if (result == NULL)
		return NULL;
	ft_strcpy(result, s);
	return result;
}
