/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:58:43 by dcaetano          #+#    #+#             */
/*   Updated: 2026/09/07 18:57:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/tester_bonus.h"

uintmax_t g_tests_passed = 0;
uintmax_t g_tests_failed = 0;

const t_array g_strs[] = {
	STRS_ARRAY("101010"),
	STRS_ARRAY("52"),
	STRS_ARRAY("42"),
	STRS_ARRAY("2A"),
	STRS_ARRAY("2a"),
	STRS_ARRAY("ta"),
	STRS_ARRAY("iii"),
	STRS_ARRAY("110110001000111001101"),
	STRS_ARRAY("6610715"),
	STRS_ARRAY("1774029"),
	STRS_ARRAY("1B11CD"),
	STRS_ARRAY("1b11cd"),
	STRS_ARRAY("dcaetano"),
	STRS_ARRAY("divadadvavd"),
	STRS_ARRAY("100111001"),
	STRS_ARRAY("471"),
	STRS_ARRAY("313"),
	STRS_ARRAY("139"),
	STRS_ARRAY("139"),
	STRS_ARRAY("tdo"),
	STRS_ARRAY("david"),
	STRS_ARRAY("10000000000000000000000000000000"),
	STRS_ARRAY("20000000000"),
	STRS_ARRAY("2147483648"),
	STRS_ARRAY("80000000"),
	STRS_ARRAY("80000000"),
	STRS_ARRAY("cancendccctd"),
	STRS_ARRAY("iaaaaaaaaaaaaaaa"),
	STRS_ARRAY("10000000000000000000000000000001"),
	STRS_ARRAY("20000000001"),
	STRS_ARRAY("2147483649"),
	STRS_ARRAY("80000001"),
	STRS_ARRAY("80000001"),
	STRS_ARRAY("cancendcccte"),
	STRS_ARRAY("iaaaaaaaaaaaaaad"),
};

const t_array g_bases[] = {
	BASES_ARRAY("01"),
	BASES_ARRAY("01234567"),
	BASES_ARRAY("0123456789"),
	BASES_ARRAY("0123456789ABCDEF"),
	BASES_ARRAY("0123456789abcdef"),
	BASES_ARRAY("acdenot"),
	BASES_ARRAY("adiv"),
	BASES_ARRAY("dcaetano"),
	BASES_ARRAY("david"),
};

const t_larray tests[] = {
	LARRAY_NULL,
	LARRAY(((const char[]){'1', '2', '3', '4', '5'})),
	LARRAY(((const char[]){'1', '2', '3', '4', '5'})),
	LARRAY(((const int[]){1, 2, 3, 4, 5})),
	LARRAY(((const float[]){1.0F, 2.0F, 3.0F, 4.0F, 5.0F})),
	LARRAY(((const double[]){1.0, 2.0, 3.0, 4.0, 5.0})),
	LARRAY(((const t_data[]){TDATA(1, "Jack"), TDATA(1, "Brian"), TDATA(1, "Paul"), TDATA(1, "Tony"), TDATA(1, "John"),
							 TDATA(2, "Jack"), TDATA(2, "Brian"), TDATA(2, "Paul"), TDATA(2, "Tony"), TDATA(2, "John"),
							 TDATA(3, "Jack"), TDATA(3, "Brian"), TDATA(3, "Paul"), TDATA(3, "Tony"), TDATA(3, "John"),
							 TDATA(4, "Jack"), TDATA(4, "Brian"), TDATA(4, "Paul"), TDATA(4, "Tony"), TDATA(4, "John"),
							 TDATA(5, "Jack"), TDATA(5, "Brian"), TDATA(5, "Paul"), TDATA(5, "Tony"), TDATA(5, "John")})),
	LARRAY(((const char[]){'1', '2', '3', '4', '5', '1', '2', '3', '4', '5'})),
	LARRAY(((const int[]){1, 2, 3, 4, 5, 1, 2, 3, 4, 5})),
	LARRAY(((const float[]){1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F})),
	LARRAY(((const double[]){1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0})),
	LARRAY(((const t_data[]){TDATA(1, "Jack"), TDATA(1, "Brian"), TDATA(1, "Paul"), TDATA(1, "Tony"), TDATA(1, "John"),
							 TDATA(2, "Jack"), TDATA(2, "Brian"), TDATA(2, "Paul"), TDATA(2, "Tony"), TDATA(2, "John"),
							 TDATA(3, "Jack"), TDATA(3, "Brian"), TDATA(3, "Paul"), TDATA(3, "Tony"), TDATA(3, "John"),
							 TDATA(4, "Jack"), TDATA(4, "Brian"), TDATA(4, "Paul"), TDATA(4, "Tony"), TDATA(4, "John"),
							 TDATA(5, "Jack"), TDATA(5, "Brian"), TDATA(5, "Paul"), TDATA(5, "Tony"), TDATA(5, "John"),
							 TDATA(1, "Jack"), TDATA(1, "Brian"), TDATA(1, "Paul"), TDATA(1, "Tony"), TDATA(1, "John"),
							 TDATA(2, "Jack"), TDATA(2, "Brian"), TDATA(2, "Paul"), TDATA(2, "Tony"), TDATA(2, "John"),
							 TDATA(3, "Jack"), TDATA(3, "Brian"), TDATA(3, "Paul"), TDATA(3, "Tony"), TDATA(3, "John"),
							 TDATA(4, "Jack"), TDATA(4, "Brian"), TDATA(4, "Paul"), TDATA(4, "Tony"), TDATA(4, "John"),
							 TDATA(5, "Jack"), TDATA(5, "Brian"), TDATA(5, "Paul"), TDATA(5, "Tony"), TDATA(5, "John")})),
};

const size_t g_strs_size = ARRAY_SIZE(g_strs);

const size_t g_bases_size = ARRAY_SIZE(g_bases);

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
	fprintf_and_fflush(stdout, CTEXT("%*s", CINFO) ": ", 15, function_name);
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
		&test_atoi_base,
		&test_list_push_front,
		&test_list_size,
		&test_list_sort,
		&test_list_remove_if,
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
