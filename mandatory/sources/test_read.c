/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:14:59 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:22:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_read(const t_array *const buf)
{
	if (buf == NULL || buf->data == NULL)
		return true;
	const size_t size = buf->size;
	int expected_pipefd[2];
	int provided_pipefd[2];
	if (pipe(expected_pipefd) == -1)
		return true;
	if (pipe(provided_pipefd) == -1)
	{
		close(expected_pipefd[1]);
		close(expected_pipefd[0]);
		return true;
	}
	write(expected_pipefd[1], buf->data, size);
	char expected_buffer[size];
	memset(expected_buffer, 0, size);
	errno = 0;
	const ssize_t expected = read(expected_pipefd[0], expected_buffer, size);
	const int expected_errno = errno;
	close(expected_pipefd[1]);
	close(expected_pipefd[0]);
	write(provided_pipefd[1], buf->data, size);
	char provided_buffer[size];
	memset(provided_buffer, 0, size);
	errno = 0;
	const ssize_t provided = ft_read(provided_pipefd[0], provided_buffer, size);
	const int provided_errno = errno;
	close(provided_pipefd[1]);
	close(provided_pipefd[0]);
	return expected == provided &&
		   expected_errno == provided_errno &&
		   memcmp(expected_buffer, provided_buffer, size) == 0;
}

void test_read(void)
{
	function_info(__func__ + 5);
	for (size_t i = 0; i < g_strs_size; i++)
	{
		if (i > 0)
			fprintf_and_fflush(stdout, " ");
		(check_read(g_strs + i) == true) ? test_passed()
										 : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
