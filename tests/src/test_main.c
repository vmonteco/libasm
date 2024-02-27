/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:22:32 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/27 04:18:53 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tests.h"

int		tests_ran = 0;
int		tests_success = 0;

void	print_single_result(int res, int *local_tests_ran, int *local_tests_success){
	(*local_tests_ran)++;
	if (res)
	{
		(*local_tests_success)++;
		printf("%sOK%s\n", COLOR_GREEN, COLOR_RESET);
	}
	else
	{
		printf("%sKO%s\n", COLOR_RED, COLOR_RESET);
	}
}

void	print_section_result(char *name, int tests_ran, int tests_success)
{
	printf(
		"%s : [%s% 2d/% 2d%s]\n",
		name,
		((tests_success == tests_ran) ? COLOR_GREEN : COLOR_RED),
		tests_success,
		tests_ran,
		COLOR_RESET
	);
}

int main(void)
{
	test_ft_strlen();
	/* test_ft_strcpy(); */
	/* test_ft_strcmp(); */
	/* test_ft_write(); */
	/* test_ft_read(); */
	/* test_ft_strdup(); */
	print_section_result("libasm - mandatory part result", tests_ran, tests_success);
	return EXIT_SUCCESS;
}
