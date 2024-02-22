;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/22 01:14:01 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/22 02:00:47 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_strcpy

ft_strcpy:
	; rdi will contain dst
	; rsi will contain src
	; At the end, rax will contain the return value

.ft_strcpy_loop:
	
	
.ft_strcpy_end:
	ret
