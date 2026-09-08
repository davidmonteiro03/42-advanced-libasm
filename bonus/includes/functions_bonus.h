/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 09:39:08 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 09:16:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/tester_bonus.h"

void test_atoi_base(void);
void test_list_push_front(void);
void test_list_size(void);
void test_list_sort(void);
void test_list_remove_if(void);

// alloc functions
void *alloc_char(const void *const data);
void *alloc_int(const void *const data);
void *alloc_float(const void *const data);
void *alloc_double(const void *const data);
void *alloc_data(const void *const data);

// free functions
void free_char(void *data);
void free_int(void *data);
void free_float(void *data);
void free_double(void *data);
void free_data(void *data);

// print functions
void print_char(const void *const data);
void print_int(const void *const data);
void print_float(const void *const data);
void print_double(const void *const data);
void print_data(const void *const data);

// compare functions
int cmp_chars(const void *const data1, const void *const data2);
int cmp_ints(const void *const data1, const void *const data2);
int cmp_floats(const void *const data1, const void *const data2);
int cmp_doubles(const void *const data1, const void *const data2);
int cmp_datas(const void *const data1, const void *const data2);

#define ALLOC_FUNCTION(x) _Generic((x), \
	char: &alloc_char,                  \
	int: &alloc_int,                    \
	float: &alloc_float,                \
	double: &alloc_double,              \
	t_data: &alloc_data,                \
	default: NULL)

#define FREE_FUNCTION(x) _Generic((x), \
	char: &free_char,                  \
	int: &free_int,                    \
	float: &free_float,                \
	double: &free_double,              \
	t_data: &free_data,                \
	default: NULL)

#define PRINT_FUNCTION(x) _Generic((x), \
	char: &print_char,                  \
	int: &print_int,                    \
	float: &print_float,                \
	double: &print_double,              \
	t_data: &print_data,                \
	default: NULL)

#define CMP_FUNCTION(x) _Generic((x), \
	char: &cmp_chars,                 \
	int: &cmp_ints,                   \
	float: &cmp_floats,               \
	double: &cmp_doubles,             \
	t_data: &cmp_datas,               \
	default: NULL)

// list utils
void list_push_front(t_list **const begin_list, void *const data);
void list_clear(t_list **const begin_list, void (*const free_fct)(void *));
