/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:16:12 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 11:07:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.h"

static bool check_write(const t_array *const buf)
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
	errno = 0;
	const ssize_t expected = write(expected_pipefd[1], buf->data, size);
	const int expected_errno = errno;
	char expected_buffer[size];
	memset(expected_buffer, 0, size);
	read(expected_pipefd[0], expected_buffer, size);
	close(expected_pipefd[1]);
	close(expected_pipefd[0]);
	errno = 0;
	const ssize_t provided = ft_write(provided_pipefd[1], buf->data, size);
	const int provided_errno = errno;
	char provided_buffer[size];
	memset(provided_buffer, 0, size);
	read(provided_pipefd[0], provided_buffer, size);
	close(provided_pipefd[1]);
	close(provided_pipefd[0]);
	return expected == provided &&
		   expected_errno == provided_errno &&
		   memcmp(expected_buffer, provided_buffer, size) == 0;
}

void test_write(void)
{
	function_info(__func__ + 5);
	for (size_t i = 0; i < g_strs_size; i++)
	{
		if (i > 0)
			fprintf_and_fflush(stdout, " ");
		(check_write(g_strs + i) == true) ? test_passed()
										  : test_failed();
	}
	fprintf_and_fflush(stdout, "\n");
}
