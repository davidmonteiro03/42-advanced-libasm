/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:39:51 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:57:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/tester_bonus.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

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

#define WHITESPACES "\t\n\v\f\r "
#define PLUS "+"
#define MINUS "-"

#define STRS_ARRAY(s)                                      \
	ARRAY(((const char *const[]){NULL, "", s,              \
								 WHITESPACES s,            \
								 PLUS s,                   \
								 MINUS s,                  \
								 WHITESPACES PLUS s,       \
								 WHITESPACES MINUS s,      \
								 PLUS WHITESPACES s,       \
								 PLUS MINUS s,             \
								 MINUS WHITESPACES s,      \
								 MINUS PLUS s,             \
								 WHITESPACES PLUS MINUS s, \
								 WHITESPACES MINUS PLUS s, \
								 PLUS WHITESPACES MINUS s, \
								 PLUS MINUS WHITESPACES s, \
								 MINUS WHITESPACES PLUS s, \
								 MINUS PLUS WHITESPACES s}))

#define BASES_ARRAY(b)                          \
	ARRAY(((const char *const[]){NULL, "", b,   \
								 WHITESPACES b, \
								 b WHITESPACES, \
								 WHITESPACES b WHITESPACES}))

typedef struct s_data
{
	const size_t id;
	const char *const name;
} t_data;

#define TDATA(i, n)                     \
	{                                   \
		.id = (const size_t)(i),        \
		.name = (const char *const)(n), \
	}

typedef struct s_larray
{
	const void *const data;
	const size_t size;
	const size_t elem_size;
	void *(*const alloc_fct)(const void *const);
	void (*const free_fct)(void *);
	void (*const print_fct)(const void *const);
	int (*const cmp_fct)(const void *const, const void *const);
} t_larray;

#define LARRAY_NULL                                                            \
	{                                                                          \
		.data = (const void *const)(NULL),                                     \
		.size = (const size_t)(0),                                             \
		.elem_size = (const size_t)(0),                                        \
		.alloc_fct = (void *(*const)(const void *const))(NULL),                \
		.free_fct = (void (*const)(void *))(NULL),                             \
		.print_fct = (void (*const)(const void *const))(NULL),                 \
		.cmp_fct = (int (*const)(const void *const, const void *const))(NULL), \
	}

#define LARRAY(arr)                                                                              \
	{                                                                                            \
		.data = (const void *const)(arr),                                                        \
		.size = (const size_t)(sizeof(arr) / sizeof((arr)[0])),                                  \
		.elem_size = (const size_t)(sizeof((arr)[0])),                                           \
		.alloc_fct = (void *(*const)(const void *const))(ALLOC_FUNCTION((arr)[0])),              \
		.free_fct = (void (*const)(void *))(FREE_FUNCTION((arr)[0])),                            \
		.print_fct = (void (*const)(const void *const))(PRINT_FUNCTION((arr)[0])),               \
		.cmp_fct = (int (*const)(const void *const, const void *const))(CMP_FUNCTION((arr)[0])), \
	}
