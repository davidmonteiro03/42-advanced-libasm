/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:39:51 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:37:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/tester.h"

#define SMALL_STR(c) \
	((const char[]){c, c, c, c, c, c, c, '\x00'})

#define MEDIUM_STR(c)                                               \
	((const char[]){c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, '\x00'})

#define LARGE_STR(c)                                                \
	((const char[]){c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, \
					c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, '\x00'})

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#ifndef MIN
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
#endif // !MIN

#ifndef MAX
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
#endif // !MAX

typedef struct s_array
{
	const void *const data;
	const size_t size;
	const size_t elem_size;
} t_array;

#define ARRAY_NULL                         \
	{                                      \
		.data = (const void *const)(NULL), \
		.size = (const size_t)(0),         \
		.elem_size = (const size_t)(0),    \
	}

#define ARRAY(arr)                                              \
	{                                                           \
		.data = (const void *const)(arr),                       \
		.size = (const size_t)(sizeof(arr) / sizeof((arr)[0])), \
		.elem_size = (const size_t)(sizeof((arr)[0])),          \
	}
