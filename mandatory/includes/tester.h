/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:27:01 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/10 14:29:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../libft/mandatory/includes/libft.h"
#include "libs.h"
#include "colors.h"
#include "common.h"
#include "functions.h"

#define CTESTPASSED RGB(0, 255, 0)
#define CTESTFAILED RGB(255, 0, 0)
#define CINFO RGB(0, 255, 255)

int fprintf_and_fflush(FILE *const stream, const char *const format, ...);
void ft_memshw(const void *const buf, const size_t count);
void test_passed(void);
void test_failed(void);
void function_info(const char *const function_name);

extern const t_array g_strs[];
extern const size_t g_strs_size;
