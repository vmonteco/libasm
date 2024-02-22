/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:52:32 by vmonteco          #+#    #+#             */
/*   Updated: 2024/02/22 06:03:43 by vmonteco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *restrict dst, const char *restrict src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *ptr, size_t count);
ssize_t		ft_read(int fd, void *ptr, size_t count);
char		*ft_strdup(const char *s);

#endif
