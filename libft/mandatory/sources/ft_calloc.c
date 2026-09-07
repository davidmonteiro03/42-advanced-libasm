/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:12:06 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 16:46:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <limits.h>

void *ft_calloc(size_t nmemb, size_t size)
{
	if (size != 0 && nmemb > LLONG_MAX / size)
		return NULL;
	void *buf = malloc(nmemb * size);
	if (buf == NULL)
		return NULL;
	for (size_t i = 0; i < nmemb * size; i++)
		*((unsigned char *)(buf + i)) = '\0';
	return buf;
}
