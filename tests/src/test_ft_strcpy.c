/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:35:57 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/28 04:48:57 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "tests.h"

extern int		tests_ran;
extern int		tests_success;

int				ft_strcpy_tests_ran = 0;
int				ft_strcpy_tests_success = 0;


void ft_strcpy_testcase(char *str){
	char		*dst1;
	char		*dst2;
	char		*strcpy_res;
	char		*ft_strcpy_res;
	size_t		strcmp_res1;
	size_t		strcmp_res2;
	int			size = strlen(str) + 1;

	printf("## Test case - \"%s\" :\n", str);
	if ((dst1 = malloc(size))){
		if ((dst2 = malloc(size))){
			bzero(dst1, size);
			bzero(dst2, size);
			printf(
				"- strcpy returned pointer : %p\n  original pointer : %p\n",
				(strcpy_res = strcpy(dst1, str)),
				dst1
			);
			printf(
				"  strcmp result with original (expected 0) : %ld\n",
				(strcmp_res1 = strcmp(dst1, str))
			);
			printf(
				"- ft_strcpy returned pointer : %p\n  original pointer : %p\n",
				(ft_strcpy_res = strcpy(dst2, str)),
				dst2
			);
			printf(
				"  strcmp result with original (expected 0) : %ld\n",
				(strcmp_res2 = strcmp(dst2, str))
			);
			
			print_single_result(
				dst1 == strcpy_res
				&& dst2 == ft_strcpy_res
				&& strcmp_res2 == 0,
				&ft_strcpy_tests_ran,
				&ft_strcpy_tests_success
			);
			free(dst1);
			free(dst2);
		}
		else
		{
			free(dst1);
			printf("Error : %s\n", strerror(errno));
		}
	}
	else
	{
		printf("Error : %s\n", strerror(errno));		
	}
}


void test_ft_strcpy(void)
{
	char	*very_long_string;
	int		size = 9999999;

	printf("# ft_strcpy test :\n");
	
	
	ft_strcpy_testcase("");
	ft_strcpy_testcase("foo");
	printf("## Case with very long (unprintable) string (size : %d) :\n", size);
	if ((very_long_string = malloc(size))){
		memset(very_long_string, '\xff', size-1);
		very_long_string[size-1] = 0;
		ft_strcpy_testcase(very_long_string);
	}
	else
	{
		printf("Error : %s.\n", strerror(errno));
	}
	tests_ran += ft_strcpy_tests_ran;
	tests_success += ft_strcpy_tests_success;
	print_section_result(
		"ft_strcpy tests",
		ft_strcpy_tests_ran,
		ft_strcpy_tests_success
	);
}
