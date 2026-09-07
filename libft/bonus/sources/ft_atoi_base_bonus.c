/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:06:06 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:58:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

size_t ft_strlen(const char *s);

static char *ft_strchr(const char *s, int c)
{
	if ((unsigned char)*s == (unsigned char)c)
		return (char *)s;
	if (*s == '\0')
		return NULL;
	return ft_strchr(s + 1, c);
}

static int ft_isspace(int c)
{
	return c == ' ' || (c >= '\t' && c <= '\r');
}

static bool check_base(const char *const base)
{
	if (ft_strlen(base) <= 1)
		return false;
	bool used[UCHAR_MAX + 1];
	for (size_t i = 0; i < sizeof(used) / sizeof(used[0]); i++)
		used[i] = false;
	for (char *bptr = (char *)base; *bptr != '\0'; bptr++)
	{
		if (*bptr == '+' || *bptr == '-' || ft_isspace(*bptr) != 0)
			return false;
		const size_t pos = (unsigned char)*bptr;
		if (used[pos] == true)
			return false;
		used[pos] = true;
	}
	return true;
}

int ft_atoi_base(char *str, char *base)
{
	if (check_base(base) == false)
		return 0;
	int result = 0, sign = 1;
	char *sptr = (char *)str;
	for (; *sptr != '\0' && ft_isspace(*sptr) != 0; sptr++)
		;
	if (*sptr == '+' || *sptr == '-')
		if (*sptr++ == '-')
			sign = -1;
	const size_t base_size = ft_strlen(base);
	for (; *sptr != '\0'; sptr++)
	{
		const char *const addr = ft_strchr(base, *sptr);
		if (addr == NULL)
			break;
		result = result * (int)base_size + (int)(addr - base);
	}
	return result * sign;
}
