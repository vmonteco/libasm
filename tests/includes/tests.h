/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:10:20 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/27 04:52:12 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "libasm.h"

/*
 * Colors
 */

# define COLOR_RESET "\033[1;0m"
# define COLOR_GREEN "\033[1;32m"
# define COLOR_RED "\033[31m"

void	print_single_result(int res, int *local_tests_ran, int *local_tests_success);
void	print_section_result(char *name, int tests_ran, int tests_success);
	
void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_strcmp(void);
void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_strdup(void);

#endif
