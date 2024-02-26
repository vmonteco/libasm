/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 06:17:33 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/26 17:41:00 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "tests.h"

ssize_t	ft_write_testcase(int fd, const void *ptr, size_t count)
{
	ssize_t result = 0;
	ssize_t last_result;
	
	printf("## Test case - %d, \"%s\", %lu :\n", fd, (char *)ptr, count);
	last_result = write(fd, ptr, count);
	if (last_result == -1){
		printf("Error case : %s.\n", strerror(errno));
	}
	result += last_result;

	printf("\nwrite return value : %lu.\n", last_result);
	last_result = ft_write(fd, ptr, count);
	if (last_result == -1){
		printf("Error case : %s.\n", strerror(errno));
	}
	result += last_result;
	printf("\nft_write return value : %lu.\n\n", last_result);
	return result;
}

/* Writing in files */

/* Error  cases */

/*
 *		ERRNO: 1 (EPERM)
 *		Operation not permitted
 */
void	ft_write_error_EPERM_testcase(){
	printf("\n### Error case - EPERM :\n");
}

/*
 *		ERRNO: 4
 *		Interrupted system call
 */
void	ft_write_error_EINTR_testcase(){
	printf("\n### Error case - EINTR :\n");
}

/*
 *		ERRNO: 5
 *		Input/Output error
 */
void	ft_write_error_EIO_testcase(){
	printf("\n### Error case - EIO :\n");
}

/*
 *		ERRNO: 9
 *		Bad file descriptor
 */
void	ft_write_error_EBADF_testcase(){
	int		res;
	
	printf("#### Error case - EBADF :\n");
	/* printf("#### write behaviour :\n"); */
	/* res = write(42, "FOO\n", 4); */
	/* printf("Return value : %d.\n", res); */
	/* if (res < 0) */
	/* { */
	/* 	printf("(errno: %d) Error case : %s.\n", errno, strerror(errno)); */
	/* } */
	/* else */
	/* { */
	/* 	printf("No error detected.\n"); */
	/* } */
	printf("#### ft_write behaviour :\n");
	res = ft_write(42, "FOO\n", 4);
	printf("Return value : %d.\n", res);
	if (res < 0)
	{
		printf("(errno: %d) Error case : %s.\n", errno, strerror(errno));
	}
	else
	{
		printf("No error detected.\n");
	}
	printf("\n");
}

/*
 *		ERRNO: 11
 *		Resource temporarily unavailable
 */
void	ft_write_error_EAGAIN_testcase(){
	printf("\n### Error case - EAGAIN\n");
}

/*
 *		ERRNO: 11
 *		https://stackoverflow.com/a/49421517/3156085
 */
void	ft_write_error_EAGAIN_or_EWOULDBLOCK_testcase(){
	printf("\n### Error case - EAGAIN_OR_EWOULDBLOCK :\n");
}

/*
 *		ERRNO: 14
 *		Bad address
 */
void	ft_write_error_EFAULT_testcase(){
	printf("\n### Error case - EFAULT :\n");
}

/*
 *		ERRNO: 22
 *		Invalid argument
 */
void	ft_write_error_EINVAL_testcase(){
	printf("\n### Error case - EINVAL :\n");
}

/*
 *		ERRNO: 27
 */
void	ft_write_error_EFBIG_testcase(){
	printf("\n### Error case - EFBIG :\n");
}

/*
 *		ERRNO: 28
 *		No space left on device
 */
void	ft_write_error_ENOSPC_testcase(){
	printf("\n### Error case - ENOSPC :\n");
}

/*
 *		ERRNO: 32
 *		Broken pipe
 */
void	ft_write_error_EPIPE_testcase(){
	printf("\n### Error case - EPIPE :\n");
}

/*
 *		ERRNO: 89
 *		Destination address required
 */
void	ft_write_error_EDESTADDRREQ_testcase(){
	printf("\n### Error case - EDESTADDREQ :\n");
}

/*
 *		ERRNO: 122
 *		Disk quota exceeded
 */
void	ft_write_error_EDQUOT_testcase(){
	printf("\n### Error case - EDQUOT :\n");
}

void	test_error_cases(void)
{
	printf("##Error cases :\n");
	ft_write_error_EPERM_testcase();
	ft_write_error_EINTR_testcase();
	ft_write_error_EIO_testcase();
	ft_write_error_EBADF_testcase();
	ft_write_error_EAGAIN_testcase();
	ft_write_error_EAGAIN_or_EWOULDBLOCK_testcase();
	ft_write_error_EFAULT_testcase();
	ft_write_error_EINVAL_testcase();
	ft_write_error_EFBIG_testcase();
	ft_write_error_ENOSPC_testcase();
	ft_write_error_EPIPE_testcase();
	ft_write_error_EDESTADDRREQ_testcase();
	ft_write_error_EDQUOT_testcase();
}


/* Main test function */
	
void	test_ft_write(void)
{
	/* ssize_t file_size; */
	/* char	*buf; */
	/* int		fd; */
	
	printf("# ft_write tests :\n");
	test_error_cases();
	/* ft_write_testcase(1, "", 0); */
	/* ft_write_testcase(1, "foo", 0); */
	/* ft_write_testcase(1, "", 3); */
	/* ft_write_testcase(1, "", 3); */
	/* ft_write_testcase(2, "foo", 3); */
	/* fd = open("/tmp/libftasm.test", O_CREAT); */
	/* file_size = ft_write_testcase(fd, "foo", 3); */
	/* close(fd); */
	/* if ((buf = malloc(file_size + 1))) */
	/* { */
	/* 	fd = open("/tmp/libftasm.test", 0); */
	/* 	read(fd, buf, file_size); */
	/* 	printf("Content written to file :\n%s\n", buf); */
	/* 	close(fd); */
	/* 	remove("/tmp/libftasm.test"); */
	/* } */
	/* else */
	/* { */
	/* 	printf("Couldn't allocate\n"); */
	/* } */
	/* close(fd); */
}
