/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:26 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/22 06:57:40 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"


void ft_strlen_testcase(char *str)
{
	printf("## Test case - \"%s\" :\n", str);
	printf("Return of strlen(\"%s\") : %lu.\n", str, strlen(str));
	printf("Return of ft_strlen(\"%s\") : %lu.\n", str, ft_strlen(str));
}


void test_ft_strlen(void)
{
	printf("# ft_strlen test :\n");
	ft_strlen_testcase("");
	ft_strlen_testcase("FOO");
}
