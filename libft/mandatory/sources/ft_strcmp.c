/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:12:13 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:02:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return 0;
	if ((unsigned char)*s1 != (unsigned char)*s2)
		return (unsigned char)*s1 - (unsigned char)*s2;
	return ft_strcmp(s1 + 1, s2 + 1);
}
