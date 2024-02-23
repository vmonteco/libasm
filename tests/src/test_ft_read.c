/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:02:50 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/23 04:46:20 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "tests.h"
#define FILE_CONTENT "Test with L1.\nTest with L2.\nTest with L3.\nTest with L4."

void ft_read_testcase(int fd, size_t count)
{
	void		*buf;
	ssize_t		chars_read;
	
	printf("## Test case - %d, %ld\n", fd, count);
	if ((buf = malloc(count + 1)))
	{
		printf("Test with standard read, first line:\n");
		chars_read = read(fd, buf, count);
		printf("Characters read : %s.\nNumber of characters read : %ld.\n", (char *)buf, chars_read);
		printf("Test with standard read, second line:\n");
		chars_read = read(fd, buf, count);
		printf("Characters read : %s.\nNumber of characters read : %ld.\n", (char *)buf, chars_read);
		printf("Test with ft_read, first line :\n");
		chars_read = ft_read(fd, buf, count);
		printf("Characters read : %s.\nNumber of characters read : %ld.\n", (char *)buf, chars_read);
		printf("Test with ft_read, second line :\n");
		chars_read = ft_read(fd, buf, count);
		printf("Characters read : %s.\nNumber of characters read : %ld.\n", (char *)buf, chars_read);
	}
	else
	{
		printf("Couldn't allocate");
	}
}

void test_ft_read(void)
{
	int fd;
	
	printf("# ft_read test :\n");
	ft_read_testcase(1, 0);
	ft_read_testcase(1, 10);
	ft_read_testcase(1, 100);
	/* Create file */
	fd = open("/tmp/libasm.test", O_CREAT);
	write(fd, FILE_CONTENT, strlen(FILE_CONTENT));
	ft_read_testcase(fd, 100);
	close(fd);
	remove("/tmp/libasm.test");
}
