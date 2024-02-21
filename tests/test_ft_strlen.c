/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:26 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/21 15:09:53 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"
# DEFINE FT_STRLEN_TESTCASE(CASE) printf("## Test case - %r :\nReturn of strlen(%r) : %d\nReturn of ft_strlen(%r)", CASE, strlen(CASE), ft_strlen(CASE));

void test_ft_strlen()
{
	printf("# ft_strlen test :\n");
	TESTCASE(strlen, ft_strlen, "");
	TESTCASE("FOO");
}
