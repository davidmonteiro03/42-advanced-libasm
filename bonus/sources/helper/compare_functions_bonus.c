/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:42:58 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:43:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester_bonus.h"

int cmp_chars(const void *const data1, const void *const data2)
{
	if (data1 == NULL || data2 == NULL)
		return 0;
	const char *const char_ptr_1 = (const char *const)data1;
	const char *const char_ptr_2 = (const char *const)data2;
	const char char_value_1 = (const char)*char_ptr_1;
	const char char_value_2 = (const char)*char_ptr_2;
	if (char_value_1 < char_value_2)
		return -1;
	if (char_value_1 > char_value_2)
		return 1;
	return 0;
}

int cmp_ints(const void *const data1, const void *const data2)
{
	if (data1 == NULL || data2 == NULL)
		return 0;
	const int *const int_ptr_1 = (const int *const)data1;
	const int *const int_ptr_2 = (const int *const)data2;
	const int int_value_1 = (const int)*int_ptr_1;
	const int int_value_2 = (const int)*int_ptr_2;
	if (int_value_1 < int_value_2)
		return -1;
	if (int_value_1 > int_value_2)
		return 1;
	return 0;
}

int cmp_floats(const void *const data1, const void *const data2)
{
	if (data1 == NULL || data2 == NULL)
		return 0;
	const float *const float_ptr_1 = (const float *const)data1;
	const float *const float_ptr_2 = (const float *const)data2;
	const float float_value_1 = (const float)*float_ptr_1;
	const float float_value_2 = (const float)*float_ptr_2;
	if (float_value_1 < float_value_2)
		return -1;
	if (float_value_1 > float_value_2)
		return 1;
	return 0;
}

int cmp_doubles(const void *const data1, const void *const data2)
{
	if (data1 == NULL || data2 == NULL)
		return 0;
	const double *const double_ptr_1 = (const double *const)data1;
	const double *const double_ptr_2 = (const double *const)data2;
	const double double_value_1 = (const double)*double_ptr_1;
	const double double_value_2 = (const double)*double_ptr_2;
	if (double_value_1 < double_value_2)
		return -1;
	if (double_value_1 > double_value_2)
		return 1;
	return 0;
}

int cmp_datas(const void *const data1, const void *const data2)
{
	if (data1 == NULL || data2 == NULL)
		return 0;
	const t_data *const data_ptr_1 = (const t_data *const)data1;
	const t_data *const data_ptr_2 = (const t_data *const)data2;
	const t_data data_value_1 = (const t_data)*data_ptr_1;
	const t_data data_value_2 = (const t_data)*data_ptr_2;
	if (data_value_1.id < data_value_2.id)
		return -1;
	if (data_value_1.id > data_value_2.id)
		return 1;
	return strcmp(data_value_1.name, data_value_2.name);
}
