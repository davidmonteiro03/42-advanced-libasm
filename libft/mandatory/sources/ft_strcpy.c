/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 10:58:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char *ft_strcpy(char *dest, const char *src)
{
	if (*src == '\0')
	{
		*dest = '\0';
		return dest;
	}
	*dest = *src;
	ft_strcpy(dest + 1, src + 1);
	return dest;
}
