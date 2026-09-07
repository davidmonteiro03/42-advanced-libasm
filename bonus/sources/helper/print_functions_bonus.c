/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:44:07 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:44:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester_bonus.h"

void print_char(const void *const data)
{
	if (data == NULL)
		return;
	const char *const char_ptr = (const char *const)data;
	const char char_value = (const char)*char_ptr;
	fprintf(stdout, "\'%c\'\n", char_value);
	fflush(stdout);
}

void print_int(const void *const data)
{
	if (data == NULL)
		return;
	const int *const int_ptr = (const int *const)data;
	const int int_value = (const int)*int_ptr;
	fprintf(stdout, "%d\n", int_value);
	fflush(stdout);
}

void print_float(const void *const data)
{
	if (data == NULL)
		return;
	const float *const float_ptr = (const float *const)data;
	const float float_value = (const float)*float_ptr;
	fprintf(stdout, "%.2ff\n", float_value);
	fflush(stdout);
}

void print_double(const void *const data)
{
	if (data == NULL)
		return;
	const double *const double_ptr = (const double *const)data;
	const double double_value = (const double)*double_ptr;
	fprintf(stdout, "%.2lf\n", double_value);
	fflush(stdout);
}

void print_data(const void *const data)
{
	if (data == NULL)
		return;
	const t_data *const data_ptr = (const t_data *const)data;
	const t_data data_value = (const t_data)*data_ptr;
	fprintf(stdout, "{%zu, \"%s\"}\n", data_value.id, data_value.name);
	fflush(stdout);
}
