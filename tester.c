/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:49:49 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/10 17:03:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/tester.h"

uintmax_t g_tests_passed = 0;
uintmax_t g_tests_failed = 0;

const t_array g_strs[] = {
	ARRAY_NULL,
	ARRAY(""),
	ARRAY("\x00\x0A\x2A\xFF"),
	ARRAY("\x00\x0A\xFF\x2A"),
	ARRAY("\x00\x2A\x0A\xFF"),
	ARRAY("\x00\x2A\xFF\x0A"),
	ARRAY("\x00\xFF\x0A\x2A"),
	ARRAY("\x00\xFF\x2A\x0A"),
	ARRAY("\x0A\x00\x2A\xFF"),
	ARRAY("\x0A\x00\xFF\x2A"),
	ARRAY("\x0A\x2A\x00\xFF"),
	ARRAY("\x0A\x2A\xFF\x00"),
	ARRAY("\x0A\xFF\x00\x2A"),
	ARRAY("\x0A\xFF\x2A\x00"),
	ARRAY("\x2A\x00\x0A\xFF"),
	ARRAY("\x2A\x00\xFF\x0A"),
	ARRAY("\x2A\x0A\x00\xFF"),
	ARRAY("\x2A\x0A\xFF\x00"),
	ARRAY("\x2A\xFF\x00\x0A"),
	ARRAY("\x2A\xFF\x0A\x00"),
	ARRAY("\xFF\x00\x0A\x2A"),
	ARRAY("\xFF\x00\x2A\x0A"),
	ARRAY("\xFF\x0A\x00\x2A"),
	ARRAY("\xFF\x0A\x2A\x00"),
	ARRAY("\xFF\x2A\x00\x0A"),
	ARRAY("\xFF\x2A\x0A\x00"),
	ARRAY("42 Porto"),
	ARRAY("dcaetano"),
	ARRAY("Mastermind dcaetano"),
	ARRAY(SMALL_STR('\x00')),
	ARRAY(MEDIUM_STR('\x00')),
	ARRAY(LARGE_STR('\x00')),
	ARRAY(SMALL_STR('\x0A')),
	ARRAY(MEDIUM_STR('\x0A')),
	ARRAY(LARGE_STR('\x0A')),
	ARRAY(SMALL_STR('\x2A')),
	ARRAY(MEDIUM_STR('\x2A')),
	ARRAY(LARGE_STR('\x2A')),
	ARRAY(SMALL_STR('\xFF')),
	ARRAY(MEDIUM_STR('\xFF')),
	ARRAY(LARGE_STR('\xFF')),
};

const size_t g_strs_size = ARRAY_SIZE(g_strs);

int fprintf_and_fflush(FILE *const stream, const char *const format, ...)
{
	va_list args;
	va_start(args, format);
	int ret = vfprintf(stream, format, args);
	va_end(args);
	if (ret >= 0)
		fflush(stream);
	return ret;
}

void test_passed(void)
{
	g_tests_passed++;
	fprintf_and_fflush(stdout, CTEXT("OK", CTESTPASSED));
}

void test_failed(void)
{
	g_tests_failed++;
	fprintf_and_fflush(stdout, CTEXT("KO", CTESTFAILED));
}

void function_info(const char *const function_name)
{
	fprintf_and_fflush(stdout, CTEXT("%*s", CINFO) ": ", 6, function_name);
}

static void log_results(void)
{
	fprintf_and_fflush(stdout, CTEXT("TESTS PASSED", BOLD CTESTPASSED) CTEXT(":", BOLD) " " CTEXT("%llu", BOLD CTESTPASSED) "\n", g_tests_passed);
	fprintf_and_fflush(stdout, CTEXT("TESTS FAILED", BOLD CTESTFAILED) CTEXT(":", BOLD) " " CTEXT("%llu", BOLD CTESTFAILED) "\n", g_tests_failed);
	fprintf_and_fflush(stdout, CTEXT("TESTS TOTAL", BOLD CINFO) " " CTEXT(":", BOLD) " " CTEXT("%llu", BOLD CINFO) "\n", g_tests_passed + g_tests_failed);
}

static void check_results(void)
{
	(g_tests_passed > 0 && g_tests_failed == 0) ? fprintf_and_fflush(stdout, CTEXT("ALL TESTS PASSED! CONGRATULATIONS!", BOLD CTESTPASSED) "\n")
												: fprintf_and_fflush(stdout, CTEXT("You failed... don't panic! Try better next time!", BOLD CTESTFAILED) "\n");
}

int main(void)
{
	void (*const test_functions[])(void) = {
		&test_strlen,
		&test_strcpy,
		&test_strcmp,
		&test_write,
		&test_read,
		&test_strdup,
		&test_calloc,
	};

	const size_t test_functions_size = ARRAY_SIZE(test_functions);
	for (size_t i = 0; i < test_functions_size; i++)
		(*(test_functions[i]))();
	fprintf_and_fflush(stdout, "\n");

	log_results();
	fprintf_and_fflush(stdout, "\n");

	check_results();
	fprintf_and_fflush(stdout, "\n");

	return 0;
}
