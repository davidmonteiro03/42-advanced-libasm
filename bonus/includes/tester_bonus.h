/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:26:36 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/08 07:09:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../libft/bonus/includes/libft_bonus.h"
#include "libs_bonus.h"
#include "colors_bonus.h"
#include "common_bonus.h"
#include "functions_bonus.h"

#define CTESTPASSED RGB(0, 255, 0)
#define CTESTFAILED RGB(255, 0, 0)
#define CINFO RGB(0, 255, 255)

int atoi_base(const char *const str, const char *const base);
int fprintf_and_fflush(FILE *const stream, const char *const format, ...);
void test_passed(void);
void test_failed(void);
void function_info(const char *const function_name);

extern const t_array g_strs[];
extern const t_array g_bases[];
extern const t_larray g_larrs[];
extern const size_t g_strs_size;
extern const size_t g_bases_size;
extern const size_t g_larrs_size;
