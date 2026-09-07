/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:12:21 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:20:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <sys/syscall.h>
#include <unistd.h>

ssize_t ft_write(int fd, const void *buf, size_t count)
{
	return syscall(SYS_write, fd, buf, count);
}
