/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:43:37 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:43:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester_bonus.h"

void free_char(void *data)
{
	if (data == NULL)
		return;
	char *char_ptr = (char *)data;
	free(char_ptr);
}

void free_int(void *data)
{
	if (data == NULL)
		return;
	int *int_ptr = (int *)data;
	free(int_ptr);
}

void free_float(void *data)
{
	if (data == NULL)
		return;
	float *float_ptr = (float *)data;
	free(float_ptr);
}

void free_double(void *data)
{
	if (data == NULL)
		return;
	double *double_ptr = (double *)data;
	free(double_ptr);
}

void free_data(void *data)
{
	if (data == NULL)
		return;
	t_data *data_ptr = (t_data *)data;
	free(data_ptr);
}
