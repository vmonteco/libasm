/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 02:57:22 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/25 13:43:30 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "tests.h"

char	c_to_h(char c){
	if (c < 10)
	{
		return c + 48;
	}
	else
	{
		return c - 10 + 65;
	}
}

char	*ft_str_to_unsigned_char_vals(char *str){
	char	*res;
	char	c;
	int		i;
	
	i = 0;
	if ((res = malloc((strlen(str) + 1) * 6 + 1)))
	{
		while (*str){
			
			c = *str;
			
			res[i*6] = '0';
			res[i*6+1] = 'x';
			res[i*6+3] = c_to_h(c & 0x0f);
			res[i*6+2] = c_to_h((c & 0xf0) >> 4);
			res[i*6+4] = ',';
			res[i*6+5] = ' ';
			i++;
			str++;
		}
		res[i*6] = '0';
		res[i*6+1] = 'x';
		res[i*6+3] = c_to_h(0);
		res[i*6+2] = c_to_h(0);
		res[i*6+4] = ',';
		res[i*6+5] = ' ';
		i++;
	}
	return res;
		
}

void ft_strcmp_testcase(char *str1, char *str2)
{
	printf("## Test case - \"%s\", \"%s\" :\n", str1, str2);
	printf(
		"Return of strcmp(\"%s\", \"%s\") : %d\n", str1, str2,
		strcmp(str1, str2)
	);
	printf(
		"Return of ft_strcmp(\"%s\", \"%s\") : %d.\n\n", str1, str2,
		ft_strcmp(str1, str2)
	);
}

void ft_strcmp_testcase_unprintable(char *str1, char *str2)
{
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_str_to_unsigned_char_vals(str1)))
	{
		if ((tmp2 = ft_str_to_unsigned_char_vals(str2)))
		{
			printf("## Test case - [%s], [%s] :\n", tmp1, tmp2);
			printf(
				"Return of strcmp([%s], [%s]) : %d\n", tmp1, tmp2,
				strcmp(str1, str2)
				);
			printf(
				"Return of ft_strcmp([%s], [%s]) : %d.\n\n", tmp1, tmp2,
				ft_strcmp(str1, str2)
				);
			free(tmp1);
			free(tmp2);
		}
		else
		{
			printf("Couldn't allocate tmp2");
			free(tmp1);
		}		
	}
	else
	{
		printf("Couldn't allocate tmp1");
	}
}

void test_ft_strcmp(void)
{
	char *test;
	if ((test = ft_str_to_unsigned_char_vals("foo")))
	{
		printf("[%s]\n", test);
		free(test);
	}
	printf("# ft_strcmp test :\n");
	ft_strcmp_testcase("", "");
	ft_strcmp_testcase("foo", "");
	ft_strcmp_testcase("", "foo");
	ft_strcmp_testcase("foo", "foo");
	ft_strcmp_testcase("foo", "bar");
	ft_strcmp_testcase_unprintable("", "\x01");
	ft_strcmp_testcase_unprintable("", "\x7f");
	ft_strcmp_testcase_unprintable("", "\x80");
	ft_strcmp_testcase_unprintable("", "\xff");
	ft_strcmp_testcase_unprintable("\x01", "");
	ft_strcmp_testcase_unprintable("\x01", "\x01");
	ft_strcmp_testcase_unprintable("\x01", "\x7f");
	ft_strcmp_testcase_unprintable("\x01", "\x80");
	ft_strcmp_testcase_unprintable("\x01", "\xff");
	ft_strcmp_testcase_unprintable("\x7f", "");
	ft_strcmp_testcase_unprintable("\x7f", "\x01");
	ft_strcmp_testcase_unprintable("\x7f", "\x7f");
	ft_strcmp_testcase_unprintable("\x7f", "\x80");
	ft_strcmp_testcase_unprintable("\x7f", "\xff");
	ft_strcmp_testcase_unprintable("\x80", "");
	ft_strcmp_testcase_unprintable("\x80", "\x01");
	ft_strcmp_testcase_unprintable("\x80", "\x7f");
	ft_strcmp_testcase_unprintable("\x80", "\x80");
	ft_strcmp_testcase_unprintable("\x80", "\xff");
	ft_strcmp_testcase_unprintable("\xff", "");
	ft_strcmp_testcase_unprintable("\xff", "\x01");
	ft_strcmp_testcase_unprintable("\xff", "\x7f");
	ft_strcmp_testcase_unprintable("\xff", "\x80");
	ft_strcmp_testcase_unprintable("\xff", "\xff");
}
