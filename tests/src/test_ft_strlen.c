/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:26 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/27 04:53:11 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "tests.h"

extern int		tests_ran;
extern int		tests_success;

int		ft_strlen_tests_ran = 0;
int		ft_strlen_tests_success = 0;

void ft_strlen_testcase(char *str)
{
	size_t	strlen_res;
	size_t	ft_strlen_res;

	printf("## Test case - \"%s\" :\n", str);
	strlen_res = strlen(str);
	ft_strlen_res = ft_strlen(str);
	printf("Return of strlen(\"%s\") : %lu.\n", str, strlen_res);
	printf("Return of ft_strlen(\"%s\") : %lu.\n", str, ft_strlen_res);
	print_single_result(strlen_res == ft_strlen_res, &ft_strlen_tests_ran, &ft_strlen_tests_success);
}


void test_ft_strlen(void)
{
	char	*very_long_string;
	int		size = 9994096;
	
	printf("# ft_strlen test :\n");
	ft_strlen_testcase("");
	ft_strlen_testcase("FOO");
	printf("## Test with unprintable chars :\n");
	ft_strlen_testcase("\xff\xff");
	printf("## Test with very long (unprintable) string :\n");
	if ((very_long_string = malloc(size))){
		memset(very_long_string, '\xff', size - 1);
		very_long_string[size - 1] = 0;
		ft_strlen_testcase(very_long_string);
	}
	else
	{
		printf("ERROR : %s.\n", strerror(errno));
	}
	tests_ran += ft_strlen_tests_ran;
	tests_success += ft_strlen_tests_success;
	print_section_result("ft_strlen tests", ft_strlen_tests_ran, ft_strlen_tests_success);
}
