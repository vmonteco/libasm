/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 06:17:33 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/22 14:56:19 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

ssize_t	ft_write_testcase(int fd, const void *ptr, size_t count)
{
	ssize_t result = 0;
	ssize_t last_result;
	
	printf("## Test case - %d, \"%s\", %lu :\n", fd, ptr, count);
	last_result = write(fd, ptr, count);
	result += last_result;
	printf("write return value : %llu.", last_result);
	last_result = write(fd, ptr, count);
	result += last_result;
	printf("ft_write return value : %llu.", last_result);
	return result;
}

void	test_ft_write(void)
{
	ssize_t file_size;
	char	*buf;
	int		fd;
	
	printf("# ft_write test :\n");
	ft_write_testcase(1, "", 0);
	ft_write_testcase(1, "foo", 0);
	ft_write_testcase(1, "", 3);
	ft_write_testcase(1, "", 3);
	ft_write_testcase(2, "foo", 3);
	fd = open("/tmp/libftasm.test", O_CREAT | O_READ);
	file_size = ft_write_testcase(fd, "foo", 3);
	close(fd);
	if ((buf = malloc(file_size + 1)))
	{
		fd = open("/tmp/libftasm.test", O_READ);
		read(fd, buf, file_size);
		printf("Content written to file :\n", buf);
		close(fd);
		remove("/tmp/libftasm.test");
	}
	else
	{
		printf("Couldn't allocate\n");
	}
	close(fd);
}
