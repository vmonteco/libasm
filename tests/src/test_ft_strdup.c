/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:27 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/22 15:55:51 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> 
#include "tests.h"

void	ft_strdup_testcase(const char *s)
{
	char	*copy;

	printf("## Test case - \"%s\", %x (address) :\n");
	copy = strdup(s);
	printf("Result with standard strdup : \"%s\" at %x.\n", copy, copy);
	free(copy);
	copy = strdup(s);
	printf("Result with ft_strdup : \"%s\" at %x.\n", copy, copy);
	free(copy);
}


void	test_ft_write(void)
{
	printf(" ft_strdup test :\n");
	ft_strdup_testcase("");
	ft_strdup_testcase("foo");	
}
