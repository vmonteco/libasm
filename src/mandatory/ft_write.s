;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:48:45 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/26 16:30:14 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_write


	;; fd in rdi
	;; buf in rsi
	;; count in rdx
ft_write:
	mov		rax, 0x01
	syscall
	ret
