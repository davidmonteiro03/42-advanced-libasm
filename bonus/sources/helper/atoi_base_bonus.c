/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:28:26 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/10 18:36:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester_bonus.h"

static bool check_base(const char *const base)
{
	if (strlen(base) <= 1)
		return false;
	for (char *bptr = (char *)base; *bptr != '\0'; bptr++)
	{
		if (*bptr == '+' || *bptr == '-' || isspace(*bptr) != 0)
			return false;
		for (char *auxptr = (char *)base; *auxptr != '\0'; auxptr++)
			if (bptr != auxptr && *bptr == *auxptr)
				return false;
	}
	return true;
}

int atoi_base(const char *const str, const char *const base)
{
	if (check_base(base) == false)
		return 0;
	int result = 0, sign = 1;
	char *sptr;
	for (sptr = (char *)str; *sptr != '\0' && isspace(*sptr) != 0; sptr++)
		;
	if (*sptr == '+' || *sptr == '-')
		if (*sptr++ == '-')
			sign = -1;
	const size_t base_size = strlen(base);
	for (; *sptr != '\0'; sptr++)
	{
		const char *const addr = strchr(base, *sptr);
		if (addr == NULL)
			break;
		result = result * (int)base_size + (int)(addr - base);
	}
	return result * sign;
}
