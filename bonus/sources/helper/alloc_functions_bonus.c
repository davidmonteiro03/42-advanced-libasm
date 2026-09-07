/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:41:18 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:41:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester_bonus.h"

void *alloc_char(const void *const data)
{
	if (data == NULL)
		return NULL;
	const char *const char_ptr = (const char *const)data;
	const char char_value = (const char)*char_ptr;
	char *char_allocated_result = (char *)malloc(sizeof(char));
	if (char_allocated_result == NULL)
		return NULL;
	*char_allocated_result = char_value;
	return (void *)char_allocated_result;
}

void *alloc_int(const void *const data)
{
	if (data == NULL)
		return NULL;
	const int *const int_ptr = (const int *const)data;
	const int int_value = (const int)*int_ptr;
	int *int_allocated_result = (int *)malloc(sizeof(int));
	if (int_allocated_result == NULL)
		return NULL;
	*int_allocated_result = int_value;
	return (void *)int_allocated_result;
}

void *alloc_float(const void *const data)
{
	if (data == NULL)
		return NULL;
	const float *const float_ptr = (const float *const)data;
	const float float_value = (const float)*float_ptr;
	float *float_allocated_result = (float *)malloc(sizeof(float));
	if (float_allocated_result == NULL)
		return NULL;
	*float_allocated_result = float_value;
	return (void *)float_allocated_result;
}

void *alloc_double(const void *const data)
{
	if (data == NULL)
		return NULL;
	const double *const double_ptr = (const double *const)data;
	const double double_value = (const double)*double_ptr;
	double *double_allocated_result = (double *)malloc(sizeof(double));
	if (double_allocated_result == NULL)
		return NULL;
	*double_allocated_result = double_value;
	return (void *)double_allocated_result;
}

void *alloc_data(const void *const data)
{
	if (data == NULL)
		return NULL;
	const t_data *const data_ptr = (const t_data *const)data;
	const t_data data_value = (const t_data)*data_ptr;
	t_data *data_allocated_result = (t_data *)malloc(sizeof(t_data));
	if (data_allocated_result == NULL)
		return NULL;
	memcpy(data_allocated_result, &data_value, sizeof(t_data));
	return (void *)data_allocated_result;
}
