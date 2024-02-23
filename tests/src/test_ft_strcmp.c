/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 02:57:22 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/23 04:47:38 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "tests.h"

void ft_strcmp_testcase(char *str1, char *str2)
{
	printf("## Test case - \"%s\", \"%s\" :\n", str1, str2);
	printf(
		"Return of strcmp(\"%s\", \"%s\") : %d\n", str1, str2,
		strcmp(str1, str2)
	);
	printf(
		"Return of ft_strcmp(\"%s\", \"%s\") : %d.\n", str1, str2,
		ft_strcmp(str1, str2)
	);
}

void test_ft_strcmp(void)
{
	printf("# ft_strcmp test :\n");
	ft_strcmp_testcase("", "");
	ft_strcmp_testcase("foo", "");
	ft_strcmp_testcase("", "foo");
	ft_strcmp_testcase("foo", "foo");
	ft_strcmp_testcase("foo", "bar");
}
