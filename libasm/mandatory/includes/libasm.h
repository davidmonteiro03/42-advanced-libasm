/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 12:19:31 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/10 12:19:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);
void *ft_calloc(size_t nmemb, size_t size);
