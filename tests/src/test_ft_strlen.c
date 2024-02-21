/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:26 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/21 22:53:23 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"
#define FT_STRLEN_TESTCASE(CASE) printf("## Test case - \"%s\" :\nReturn of strlen(%s) : %lu.\nReturn of ft_strlen(%s) : %lu.\n", CASE, CASE, strlen(CASE), CASE, ft_strlen(CASE));

size_t ft_strlen(const char* ptrn);

void test_ft_strlen(void)
{
	printf("# ft_strlen test :\n");
	FT_STRLEN_TESTCASE("");
	FT_STRLEN_TESTCASE("FOO");
}
