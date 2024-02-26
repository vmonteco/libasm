;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:48:45 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/26 22:04:36 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	extern __errno_location
	global ft_write


	;; fd in rdi
	;; buf in rsi
	;; count in rdx
	;; https://github.com/bpowers/musl/blob/master/src/internal/syscall_ret.c
	
ft_write:
	mov		rax, 0x01
	syscall
	cmp rax, 0
	js	.error_handling
	jmp .end

.error_handling:
	neg		eax
	
	call	__errno_location wrt ..plt
	mov		[rax], eax
	mov		eax, -1
	
.end:
	ret
