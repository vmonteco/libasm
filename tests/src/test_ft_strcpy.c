/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:35:57 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/22 02:22:56 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "libasm.h"

void ft_strcpy_testcase(char *str){
	char *dst;

	printf("## Test case - \"%s\" :\n", str);
	if ((dst = malloc(strlen(str) + 1)))
	{
		printf("Raw print, characters printed : %d\n", printf("%s\n", str));
		dst = strcpy(dst, str);
		printf("Standard strcpy, characters printed : %d\nstrcmp with original : %d.\n", printf("%s\n", dst), strcmp(dst, str));
		bzero(dst, strlen(str) + 1);
		dst = ft_strcpy(dst, str);
		printf("ft_strcpy, characters printed : %d\nstrcmp with original : %d.\n", printf("%s\n", dst), strcmp(dst, str));
		free(dst);
	}
	else
	{
		printf("Couldn't allocate.\n");
	}
}

void test_ft_strcpy(void)
{
	printf("# ft_strcpy test :\n");
	ft_strcpy_testcase("");
	ft_strcpy_testcase("foo");
	// ft_strcpy_testcase(VERY_LONG_STR);
}
