/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:12:09 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:21:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <sys/syscall.h>
#include <unistd.h>

ssize_t ft_read(int fd, void *buf, size_t count)
{
	return syscall(SYS_read, fd, buf, count);
}
