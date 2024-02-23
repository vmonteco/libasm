/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:27 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/23 04:45:44 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h> 
#include "tests.h"

void	ft_strdup_testcase(const char *s)
{
	char	*copy;

	printf("## Test case - \"%s\", %p (address) :\n", s, (void *) s);
	copy = strdup(s);
	printf("Result with standard strdup : \"%s\" at %p.\n", copy, (void *) copy);
	free(copy);
	copy = ft_strdup(s);
	printf("Result with ft_strdup : \"%s\" at %p.\n", copy, (void *) copy);
	free(copy);
}


void	test_ft_strdup(void)
{
	printf(" ft_strdup test :\n");
	ft_strdup_testcase("");
	ft_strdup_testcase("foo");	
}
