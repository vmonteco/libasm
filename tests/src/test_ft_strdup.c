/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:27 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/22 16:07:04 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h> 
#include "tests.h"

void	ft_strdup_testcase(const char *s)
{
	char	*copy;

	printf("## Test case - \"%s\", %lx (address) :\n", s, (unsigned long) s);
	copy = strdup(s);
	printf("Result with standard strdup : \"%s\" at %lx.\n", copy, (unsigned long) copy);
	free(copy);
	copy = strdup(s);
	printf("Result with ft_strdup : \"%s\" at %lx.\n", copy, (unsigned long) copy);
	free(copy);
}


void	test_ft_write(void)
{
	printf(" ft_strdup test :\n");
	ft_strdup_testcase("");
	ft_strdup_testcase("foo");	
}
